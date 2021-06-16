
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
def insertNodeAtHead(head, data):
    if head == None:
        return SinglyLinkedListNode(data)
    newNode = SinglyLinkedListNode(data)
    newNode.next = head
    head = newNode
    return head

