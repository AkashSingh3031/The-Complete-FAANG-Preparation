class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k<2:
            return head
        node = head
        for _ in range(k):
            if not node:
                return head
            node = node.next
        prev = self.reverseKGroup(node, k)
        for _ in range(k):
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        return prev