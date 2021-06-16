
# Contributed by Paraj Shah
# https://github.com/parajshah

def preOrder(root):
    if not root:
        return
    
    print(root.info, end=" ")
    preOrder(root.left)    
    preOrder(root.right)