from insertion import linkedList, node

class newClass(linkedList):
    def insert(self, list1, list2, k):
        first = list1.head
        second = list2.head
        for i in range(k-1):
            first = first.next
        next = first.next
        while second:
            first.next = second
            second = second.next
            first = first.next
        first.next = next
        
        
if __name__ == "__main__": 
  
    """ The constructed linked lists are :
    a: 1.2.3.4.5
    b: 7.8.9.10.11 """
    a = newClass()
    b = newClass()
    k = 2
  
    # first linked list
    a.push(5)
    a.push(4)
    a.push(3)
    a.push(2)
    a.push(1)
  
    # second linked list
    b.push(11)
    b.push(10)
    b.push(9)
    b.push(8)
    b.push(7)
  
    a.printList()
    print()
  
    b.printList()
    
    
    a.insert(a, b, k)
  
    print("\nResulting linked list\t", end = " ");
    a.printList()