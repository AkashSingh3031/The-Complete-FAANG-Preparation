
# Contributed by Paraj Shah
# https://github.com/parajshah

class DoublyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None
        self.prev = None

# Solution
def sortedInsert(head, data):
    # Create new node
    newNode = DoublyLinkedListNode(data)

    if not head:
        head = newNode
        return head
    
    cur = head
    if cur.data >= data:
        newNode.next = cur
        cur.prev = newNode
        head = newNode
        return head
    else:
        while cur.next:
            if cur.data < data and cur.next.data >= data:
                newNode.prev = cur
                newNode.next = cur.next
                cur.next = newNode
                cur.next.prev = newNode
                return head
            else:
                cur = cur.next
        else:
            cur.next = newNode
            newNode.prev = cur
    return head