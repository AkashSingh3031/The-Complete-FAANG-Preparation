from insertion import linkedList

class newClass(linkedList):

    def swapNodes(self, x, y):
        if x == y:
            return 
        
        prex = None
        X = self.head
        while X and X.data != x:
            prex = X
            X = X.next

        prey = None
        Y = self.head
        while Y and Y.data != y:
            prey = Y
            Y = Y.next

        if X is None or Y is None:
            return

        if prex is None:
            self.head = Y
        else:
            prex.next = Y

        if prey is None:
            self.head = X
        else:
            prey.next = X

        X.next, Y.next = Y.next, X.next

if __name__ == '__main__':
    llist = newClass()

    llist.push(7)
    llist.push(6)
    llist.push(5)
    llist.push(4)
    llist.push(3)
    llist.push(2)
    llist.push(1)
    print("Linked list before calling swapNodes() ")
    llist.printList()
    llist.swapNodes(4, 3)
    print("\nLinked list after calling swapNodes() ")
    llist.printList()