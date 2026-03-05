// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

/**
 * @title Upload
 * @author Privex Team
 * @notice Decentralized file storage and access control via smart contract.
 * @dev Files are stored off-chain on IPFS; this contract stores metadata and controls access.
 */
contract Upload {
    // ─── Structs ────────────────────────────────────────────────────────────────

    struct FileData {
        uint256 id;
        string fileName;
        string url; // IPFS gateway URL
    }

    struct Access {
        address user;
        bool access;
        uint256[] fileIds;
    }

    struct Group {
        string name;
        address[] members;
        bool active;
    }

    // ─── State ──────────────────────────────────────────────────────────────────

    /// @notice Maps owner address → array of their files
    mapping(address => FileData[]) public value;

    /// @notice Maps owner → accessor → granted?
    mapping(address => mapping(address => bool)) public ownership;

    /// @notice Maps owner → list of access grants
    mapping(address => Access[]) public accessList;

    /// @notice Tracks whether an accessor was ever added (for update vs insert)
    mapping(address => mapping(address => bool)) public previousData;

    /// @notice Maps owner → list of groups they created
    mapping(address => Group[]) public userGroups;

    /// @notice Maps owner → groupName → index+1 (0 means not found)
    mapping(address => mapping(string => uint256)) public groupIndexByName;

    /// @dev Auto-incrementing file ID counter
    uint256 private fileIdCounter;

    // ─── Events ─────────────────────────────────────────────────────────────────

    event FileAdded(address indexed user, uint256 indexed fileId, string fileName);
    event AccessGranted(address indexed owner, address indexed accessor, uint256[] fileIds);
    event AccessRevoked(address indexed owner, address indexed accessor);
    event GroupCreated(address indexed creator, string groupName);
    event GroupMemberAdded(address indexed owner, string groupName, address member);

    // ─── File Functions ──────────────────────────────────────────────────────────

    /**
     * @notice Upload a file metadata entry.
     * @param _user The owner address (usually msg.sender from frontend).
     * @param fileName Human-readable file name.
     * @param url IPFS gateway URL of the encrypted file.
     * @return fileId The unique ID assigned to this file.
     */
    function add(
        address _user,
        string calldata fileName,
        string calldata url
    ) external returns (uint256 fileId) {
        require(bytes(fileName).length > 0, "Upload: fileName cannot be empty");
        require(bytes(url).length > 0, "Upload: url cannot be empty");

        fileId = fileIdCounter++;
        value[_user].push(FileData(fileId, fileName, url));

        emit FileAdded(_user, fileId, fileName);
    }

    /**
     * @notice Retrieve all files belonging to a user (owner-only, no access check).
     */
    function getAllFiles(address user) external view returns (FileData[] memory) {
        return value[user];
    }

    /**
     * @notice Retrieve files the caller is allowed to access.
     * @dev If caller is the owner, returns all files. Otherwise enforces access control.
     */
    function display(address user) external view returns (FileData[] memory) {
        if (user == msg.sender) {
            return value[user];
        }

        require(ownership[user][msg.sender], "Upload: access not granted");

        uint256[] memory accessibleIds;
        for (uint256 i = 0; i < accessList[user].length; i++) {
            if (accessList[user][i].user == msg.sender && accessList[user][i].access) {
                accessibleIds = accessList[user][i].fileIds;
                break;
            }
        }

        if (accessibleIds.length == 0) return new FileData[](0);

        // Count matching files
        uint256 count;
        for (uint256 i = 0; i < value[user].length; i++) {
            for (uint256 j = 0; j < accessibleIds.length; j++) {
                if (value[user][i].id == accessibleIds[j]) count++;
            }
        }

        // Build result array
        FileData[] memory result = new FileData[](count);
        uint256 idx;
        for (uint256 i = 0; i < value[user].length; i++) {
            for (uint256 j = 0; j < accessibleIds.length; j++) {
                if (value[user][i].id == accessibleIds[j]) {
                    result[idx++] = value[user][i];
                }
            }
        }
        return result;
    }

    // ─── Access Control ──────────────────────────────────────────────────────────

    /**
     * @notice Grant access to specific files to another address.
     */
    function allow(address user, uint256[] calldata fileIds) external {
        _allow(user, fileIds);
    }

    /**
     * @notice Revoke all access previously granted to an address.
     */
    function disallow(address user) external {
        ownership[msg.sender][user] = false;
        for (uint256 i = 0; i < accessList[msg.sender].length; i++) {
            if (accessList[msg.sender][i].user == user) {
                accessList[msg.sender][i].access = false;
            }
        }
        emit AccessRevoked(msg.sender, user);
    }

    /**
     * @notice Returns the full access list of the caller.
     */
    function shareAccess() external view returns (Access[] memory) {
        return accessList[msg.sender];
    }

    // ─── Group Functions ─────────────────────────────────────────────────────────

    /**
     * @notice Create a new named group and optionally add initial members.
     */
    function createGroup(string calldata groupName, address[] calldata initialMembers) external {
        require(bytes(groupName).length > 0, "Upload: groupName cannot be empty");

        uint256 existingIdx = groupIndexByName[msg.sender][groupName];
        if (existingIdx > 0) {
            require(!userGroups[msg.sender][existingIdx - 1].active, "Upload: group already active");
        }

        userGroups[msg.sender].push(Group({ name: groupName, members: new address[](0), active: true }));
        groupIndexByName[msg.sender][groupName] = userGroups[msg.sender].length;

        for (uint256 i = 0; i < initialMembers.length; i++) {
            if (initialMembers[i] != address(0)) {
                _addMember(groupName, initialMembers[i]);
            }
        }

        emit GroupCreated(msg.sender, groupName);
    }

    /**
     * @notice Add a member to an existing group.
     */
    function addToGroup(string calldata groupName, address member) external {
        _addMember(groupName, member);
    }

    /**
     * @notice Share specific files with all members of a group.
     */
    function allowGroup(string calldata groupName, uint256[] calldata fileIds) external {
        uint256 groupIdx = _getGroupIndex(groupName);
        Group storage group = userGroups[msg.sender][groupIdx];

        require(group.active, "Upload: group is not active");
        require(group.members.length > 0, "Upload: group has no members");

        for (uint256 i = 0; i < group.members.length; i++) {
            _allow(group.members[i], fileIds);
        }
    }

    /**
     * @notice Return all groups created by the caller.
     */
    function getGroups() external view returns (Group[] memory) {
        return userGroups[msg.sender];
    }

    // ─── Internal Helpers ────────────────────────────────────────────────────────

    function _allow(address user, uint256[] memory fileIds) internal {
        ownership[msg.sender][user] = true;

        if (previousData[msg.sender][user]) {
            for (uint256 i = 0; i < accessList[msg.sender].length; i++) {
                if (accessList[msg.sender][i].user == user) {
                    accessList[msg.sender][i].access = true;
                    accessList[msg.sender][i].fileIds = fileIds;
                }
            }
        } else {
            accessList[msg.sender].push(Access(user, true, fileIds));
            previousData[msg.sender][user] = true;
        }

        emit AccessGranted(msg.sender, user, fileIds);
    }

    function _addMember(string memory groupName, address member) internal {
        require(member != address(0), "Upload: invalid member address");
        uint256 groupIdx = _getGroupIndex(groupName);
        Group storage group = userGroups[msg.sender][groupIdx];
        require(group.active, "Upload: group is not active");

        for (uint256 i = 0; i < group.members.length; i++) {
            if (group.members[i] == member) return; // already a member
        }

        group.members.push(member);
        emit GroupMemberAdded(msg.sender, groupName, member);
    }

    function _getGroupIndex(string memory groupName) internal view returns (uint256) {
        uint256 idx = groupIndexByName[msg.sender][groupName];
        require(idx > 0, "Upload: group does not exist");
        return idx - 1;
    }
}
