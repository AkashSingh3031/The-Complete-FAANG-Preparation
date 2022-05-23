# Binary Tree Traversals
# Inorder, Preorder and PostOrder - Iterative

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BinaryTreeTraversals:
    def inorder(self, root):
        # Time Complexity: O(n)
        # # Space Complexity: O(n)
        if (root == None):
            return []
        node_values = []
        node_stack = []
        cur_node = root
        while (cur_node or node_stack):
            while (cur_node):
                node_stack.append(cur_node)
                cur_node = cur_node.left
            cur_node = node_stack.pop()
            node_values.append(cur_node.val)
            cur_node = cur_node.right
        return node_values
    
    def preorder(self, root):
        # Time Complexity: O(n)
        # Space Complexity: O(n)
        if (root == None):
            return []
        node_values = []
        node_stack = []
        node_stack.append(root)
        while (len(node_stack) > 0):
            top_node = node_stack.pop()
            node_values.append(top_node.val)
            if (top_node.right):
                node_stack.append(top_node.right)
            if (top_node.left):
                node_stack.append(top_node.left)
        return node_values
    
    def postorderTraversal(self, root):
        # Time Complexity: O(n)
        # Space Complexity: O(n)
        if (root == None):
            return []
        node_values = []
        node_stack = []
        node_stack.append(root)
        while (len(node_stack) > 0):
            top_node = node_stack.pop()
            node_values.append(top_node.val)
            if (top_node.left):
                node_stack.append(top_node.left)
            if (top_node.right):
                node_stack.append(top_node.right)
        node_values.reverse()
        return node_values