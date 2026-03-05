const { expect } = require("chai");
const { ethers } = require("hardhat");

describe("Upload Contract", function () {
    let upload;
    let owner, user1, user2;

    beforeEach(async function () {
        [owner, user1, user2] = await ethers.getSigners();
        const Upload = await ethers.getContractFactory("Upload");
        upload = await Upload.deploy();
        await upload.deployed();
    });

    // ─── File Management ────────────────────────────────────────────────────────

    describe("File Management", function () {
        it("Should add a file and return it", async function () {
            await upload.add(owner.address, "test.txt", "https://ipfs.io/ipfs/abc123");
            const files = await upload.getAllFiles(owner.address);
            expect(files.length).to.equal(1);
            expect(files[0].fileName).to.equal("test.txt");
            expect(files[0].url).to.equal("https://ipfs.io/ipfs/abc123");
        });

        it("Should assign incrementing IDs to files", async function () {
            await upload.add(owner.address, "file1.txt", "https://ipfs.io/ipfs/a");
            await upload.add(owner.address, "file2.txt", "https://ipfs.io/ipfs/b");
            const files = await upload.getAllFiles(owner.address);
            expect(files[0].id).to.equal(0);
            expect(files[1].id).to.equal(1);
        });

        it("Should revert if fileName is empty", async function () {
            await expect(
                upload.add(owner.address, "", "https://ipfs.io/ipfs/abc123")
            ).to.be.revertedWith("Upload: fileName cannot be empty");
        });

        it("Should revert if url is empty", async function () {
            await expect(
                upload.add(owner.address, "test.txt", "")
            ).to.be.revertedWith("Upload: url cannot be empty");
        });

        it("Should emit FileAdded event", async function () {
            await expect(upload.add(owner.address, "test.txt", "https://ipfs.io/ipfs/abc"))
                .to.emit(upload, "FileAdded")
                .withArgs(owner.address, 0, "test.txt");
        });
    });

    // ─── Access Control ─────────────────────────────────────────────────────────

    describe("Access Control", function () {
        beforeEach(async function () {
            await upload.add(owner.address, "secret.pdf", "https://ipfs.io/ipfs/xyz");
        });

        it("Owner can view their own files via display()", async function () {
            const files = await upload.display(owner.address);
            expect(files.length).to.equal(1);
        });

        it("Non-owner cannot view files without access", async function () {
            await expect(
                upload.connect(user1).display(owner.address)
            ).to.be.revertedWith("Upload: access not granted");
        });

        it("Owner can grant access to a user for specific files", async function () {
            await upload.allow(user1.address, [0]);
            const files = await upload.connect(user1).display(owner.address);
            expect(files.length).to.equal(1);
            expect(files[0].fileName).to.equal("secret.pdf");
        });

        it("Owner can revoke access", async function () {
            await upload.allow(user1.address, [0]);
            await upload.disallow(user1.address);
            await expect(
                upload.connect(user1).display(owner.address)
            ).to.be.revertedWith("Upload: access not granted");
        });

        it("shareAccess() returns the access list", async function () {
            await upload.allow(user1.address, [0]);
            const list = await upload.shareAccess();
            expect(list.length).to.equal(1);
            expect(list[0].user).to.equal(user1.address);
            expect(list[0].access).to.equal(true);
        });

        it("Should emit AccessGranted event", async function () {
            await expect(upload.allow(user1.address, [0]))
                .to.emit(upload, "AccessGranted")
                .withArgs(owner.address, user1.address, [0]);
        });

        it("Should emit AccessRevoked event", async function () {
            await upload.allow(user1.address, [0]);
            await expect(upload.disallow(user1.address))
                .to.emit(upload, "AccessRevoked")
                .withArgs(owner.address, user1.address);
        });
    });

    // ─── Group Sharing ───────────────────────────────────────────────────────────

    describe("Group Sharing", function () {
        beforeEach(async function () {
            await upload.add(owner.address, "group_file.txt", "https://ipfs.io/ipfs/grp");
        });

        it("Should create a group", async function () {
            await upload.createGroup("team", []);
            const groups = await upload.getGroups();
            expect(groups.length).to.equal(1);
            expect(groups[0].name).to.equal("team");
            expect(groups[0].active).to.equal(true);
        });

        it("Should add members to a group", async function () {
            await upload.createGroup("team", [user1.address]);
            const groups = await upload.getGroups();
            expect(groups[0].members.length).to.equal(1);
            expect(groups[0].members[0]).to.equal(user1.address);
        });

        it("Should share files with all group members", async function () {
            await upload.createGroup("team", [user1.address, user2.address]);
            await upload.allowGroup("team", [0]);
            const filesForUser1 = await upload.connect(user1).display(owner.address);
            const filesForUser2 = await upload.connect(user2).display(owner.address);
            expect(filesForUser1.length).to.equal(1);
            expect(filesForUser2.length).to.equal(1);
        });

        it("Should revert if group name is empty", async function () {
            await expect(upload.createGroup("", [])).to.be.revertedWith(
                "Upload: groupName cannot be empty"
            );
        });

        it("Should not add duplicate members to a group", async function () {
            await upload.createGroup("team", [user1.address]);
            await upload.addToGroup("team", user1.address);
            const groups = await upload.getGroups();
            expect(groups[0].members.length).to.equal(1);
        });
    });
});
