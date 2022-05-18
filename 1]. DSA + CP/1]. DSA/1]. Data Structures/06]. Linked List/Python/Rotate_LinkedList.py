from insertion import linkedList, node

class newClass(linkedList):

    def rotate(self, k):
        if k == 0:
            return 
        
        current = self.head

        count = 1

        while count<k and current is not None:
            count += 1
            current = current.next

        if current is None:
            return

        kthnode = current

        while current.next:
            current = current.next

        current.next = self.head

        self.head = kthnode.next

        kthnode.next = None

if __name__ == '__main__':
    llist = newClass()
    for i in range(60, 0, -10):
        llist.push(i)
 
    print("Given linked list")
    llist.printList()
    llist.rotate(4)
    
    print("\nRotated Linked list")
    llist.printList()