# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    
    def addTwoNumbers(self, l1, l2):
        num1, num2 = 0,0
        prod1, prod2 = 1, 1
        while l1 != None:
            num1 += prod1*l1.val
            prod1 *= 10
            l1 = l1.next
        while l2 != None:
            num2 += prod2*l2.val
            prod2 *= 10
            l2 = l2.next
        result = num1+num2

        l3 = ListNode()
        head = l3
        while result != 0:
            dig = result % 10
            l3.val = dig
            result //= 10
            if result != 0:
                l3.next = ListNode()
                l3 = l3.next
          
            
        
        
        
        return head
            
            
            
            
        
