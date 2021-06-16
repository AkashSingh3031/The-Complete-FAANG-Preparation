
# Contributed by Paraj Shah
# https://github.com/parajshah

def printLinkedList(head):
    if not head:
        return
    while head != None:        
        print(head.data)
        head = head.next