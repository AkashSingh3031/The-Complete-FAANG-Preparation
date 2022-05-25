# Binary Tree Level Order Traversal - Breadth First Search 1
# Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root):

        if not root:
            return []

        levels = []
        new_level = []
        new_level.append(root)

        while (len(new_level) != 0):

            cur_level = list(new_level)  # copy
            cur_level_values = []

            new_level.clear()
            for node in cur_level:

                cur_level_values.append(node.val)

                if (node.left):
                    new_level.append(node.left)
                if (node.right):
                    new_level.append(node.right)

            levels.append(cur_level_values)
        return levels

# Time Complexity: O(N)
# Space Complexity: O(N)
