
# Contributed by Paraj Shah
# https://github.com/parajshah

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

# Solution
def insertNodeAtTail(head, data):
    cur = head
    if head == None:
        return SinglyLinkedListNode(data)
    while cur.next != None:
        cur = cur.next
    cur.next = SinglyLinkedListNode(data)
    return head
    