
# Contributed by Paraj Shah
# https://github.com/parajshah

def inOrder(root):
    if not root:
        return
    
    inOrder(root.left)
    print(root.info, end=" ")
    inOrder(root.right)