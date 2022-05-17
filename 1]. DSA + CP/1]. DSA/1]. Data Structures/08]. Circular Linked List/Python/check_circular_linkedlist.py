from insertion import linkedList, node

def Circular(head):
    current = head
    if head is None:
        return True
    while current.next != None and current.next != head:
        current = current.next

    return (current.next == head)

if __name__=='__main__':
    llist = linkedList()
    llist.head = node(1)
    second = node(2)
    third = node(3)
    fourth = node(4)
     
    llist.head.next = second
    second.next = third
    third.next = fourth
     
    if (Circular(llist.head)):
        print('Yes')
    else:
        print('No')
     
    fourth.next = llist.head
     
    if (Circular(llist.head)):
        print('Yes')
    else:
        print('No')