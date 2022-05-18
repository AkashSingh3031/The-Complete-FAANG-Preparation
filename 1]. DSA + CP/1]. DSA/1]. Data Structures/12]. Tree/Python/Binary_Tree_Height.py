# Binary Tree Height Calculation

class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

class BinaryTree:
    def height(self, root):
        if root == None:
            return 0
        else:
            return max(self.height(root.left), self.height(root.right)) + 1


t = Node(20)
t.left = Node(10)
t.right = Node(30)
t.left.left = Node(5)
t.right.right = Node(35)
b = BinaryTree()

#Height of Binary Tree
print(b.height(t))