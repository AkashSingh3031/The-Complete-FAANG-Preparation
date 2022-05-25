# Binary Tree Level Order Traversal - Breadth First Search 1
# Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelTraverse(self, node, level):

        if (level == len(self.levels)):
            self.levels.append([])
        self.levels[level].append(node.val)

        if (node.left):
            self.levelTraverse(node.left, level + 1)
        if (node.right):
            self.levelTraverse(node.right, level + 1)

    def levelOrder(self, root):

        if not root:
            return []

        self.levels = []
        self.levelTraverse(root, 0)
        return self.levels

# Time Complexity: O(N)
# Space Complexity: O(N)
