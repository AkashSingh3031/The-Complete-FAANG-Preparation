from insertion import linkedList, node

class newClass(linkedList):

    def addTwoLists(self, first, second):
        prev = None
        temp = None
        carry = 0

        while first or second:

            fdata = 0 if first is None else first.data
            sdata = 0 if second is None else second.data

            sum = carry + fdata +sdata

            carry = 1 if sum>=10 else 0

            sum = sum if sum<10 else sum%10

            temp = node(sum)

            if self.head is None:
                self.head = temp
            else:
                prev.next = temp

            prev = temp

            if first:
                first = first.next
            if second:
                second = second.next

        if carry > 0:
            temp.next = node(carry)

# Driver's Code

first = newClass()
second = newClass()
# Create first list
first.push(6)
first.push(4)
first.push(9)
first.push(5)
first.push(7)
print( "First List is ")
first.printList()
 
# Create second list
second.push(4)
second.push(8)
print ("\nSecond List is ")
second.printList()
 
# Add the two lists and see result
res = newClass()
res.addTwoLists(first.head, second.head)
print("\nResultant list is ")
res.printList()
llist = newClass()