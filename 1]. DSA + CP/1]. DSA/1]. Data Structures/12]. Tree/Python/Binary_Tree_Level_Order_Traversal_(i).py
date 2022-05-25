# Binary Tree Level Order Traversal - Breadth First Search 1
# Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

import queue


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
        q = queue.Queue()
        q.put([root, 0])
        while not q.empty():

            top = q.get()

            while (top[1] >= len(levels)):
                levels.append([])

            levels[top[1]].append(top[0].val)

            if (top[0].left):
                q.put([top[0].left, top[1] + 1])
            if (top[0].right):
                q.put([top[0].right, top[1] + 1])
        return levels

# Time Complexity: O(N)
# Space Complexity: O(N)
