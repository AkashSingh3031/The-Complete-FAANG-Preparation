# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        cur1 = l1
        cur2 = l2
        if cur1.val <= cur2.val:
            ans = cur1
            cur1 = cur1.next
        else:
            ans = cur2
            cur2 = cur2.next
        a = ans
        while cur1 and cur2:
            if cur1.val <= cur2.val:
                a.next = cur1
                cur1 = cur1.next
            else:
                a.next = cur2
                cur2 = cur2.next
            a = a.next
        while cur1:
            a.next = cur1
            a = a.next
            cur1 = cur1.next
        while cur2:
            a.next = cur2
            a = a.next
            cur2 = cur2.next
        return ans
