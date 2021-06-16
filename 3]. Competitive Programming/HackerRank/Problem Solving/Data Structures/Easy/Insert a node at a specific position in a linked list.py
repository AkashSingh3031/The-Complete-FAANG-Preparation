
# Contributed by Paraj Shah
# https://github.com/parajshah

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

# Solution  
def insertNodeAtPosition(head, data, position):
    cur = head
    newNode = SinglyLinkedListNode(data)
    if position == 0:
        newNode.next = cur
        head = newNode
        return head
    
    while position > 1:
        position -= 1
        cur = cur.next
        
    newNode.next = cur.next
    cur.next = newNode
    return head