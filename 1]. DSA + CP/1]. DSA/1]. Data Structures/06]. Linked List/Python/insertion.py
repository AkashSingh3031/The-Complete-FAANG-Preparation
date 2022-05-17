class node:
    def __init__(self,data):
        self.data = data
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None

    def push(self, newdata):
        newNode = node(newdata)

        newNode.next = self.head

        self.head = newNode

    def insertAfter(self, prevnode, newdata):
        if prevnode is None:
            return

        newnode = node(newdata)

        newnode.next = prevnode.next
        prevnode.next = newnode

    def append(self, newdata):
        newnode = node(newdata)

        if self.head is None:
            self.head = newnode
            return 

        last = self.head
        while last.next:
            last = last.next
        
        last.next = newnode

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data,end = " ")
            temp = temp.next

if __name__ == '__main__':
    llist = linkedList()

    llist.append(6)

    llist.push(7)

    llist.push(1)

    llist.append(4)

    llist.insertAfter(llist.head.next, 8)
    
    llist.printList()