# Symmetric Tree - Iteration
# Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

import queue


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root) -> bool:

        if (root.left == None) and (root.right == None):
            return True
        elif (root.left == None):
            return False
        elif (root.right == None):
            return False

        q = queue.Queue()
        q.put(root.left)
        q.put(root.right)
        while not q.empty():
            right_root = q.get()
            left_root = q.get()
            # print(left_root, right_root)

            if (right_root == None and left_root == None):
                continue
            elif (right_root == None):
                return False
            elif (left_root == None):
                return False
            elif (right_root.val != left_root.val):
                return False

            q.put(left_root.left)
            q.put(right_root.right)
            q.put(left_root.right)
            q.put(right_root.left)
        return True

# Time Complexity: O(N)
# Space Complexity: O(N)
