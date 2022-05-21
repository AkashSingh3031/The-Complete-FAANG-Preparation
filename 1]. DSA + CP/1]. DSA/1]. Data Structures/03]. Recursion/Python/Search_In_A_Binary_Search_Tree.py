# You are given the root of a binary search tree (BST) and an integer val.
# Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
# If such a node does not exist, return null.

# Constraints:
## The number of nodes in the tree is in the range [1, 5000].
## 1 <= Node.val <= 107
## root is a binary search tree.
## 1 <= val <= 107

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    '''
    Function Description:
    Input: root of a BST and an integer
    Output: subtree of a node whose value is equal to the given integer
    '''
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        # Base case
        if not root:
            return None
        # Normal cases
        if (root.val == val):
            return root
        elif (root.val > val):
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)

# Time Complexity: O(H)
# Space Complexity: O(H)