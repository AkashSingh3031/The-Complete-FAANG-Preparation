# Given the root of a binary tree, determine if it is a valid binary search tree (BST).
# A valid BST is defined as follows:
# The left subtree of a node contains only nodes with keys less than the node's key.
# The right subtree of a node contains only nodes with keys greater than the node's key.
# Both the left and right subtrees must also be binary search trees.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidated(self, node, lower, upper):
        # Base cases
        if not node:
            return True
        elif (node.val <= lower) or (node.val >= upper):
            return False
        # Normal cases
        return self.isValidated(node.left, lower, node.val) and self.isValidated(node.right, node.val, upper)
    
    def isValidBST(self, root) -> bool:
        return self.isValidated(root, -float('inf'), float('inf'))

# Time Complexity: O(N)
# Space Complexity: O(N)