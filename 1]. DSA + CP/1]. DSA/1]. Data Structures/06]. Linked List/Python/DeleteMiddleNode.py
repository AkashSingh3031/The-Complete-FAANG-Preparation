class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, val):
        new_node = ListNode(val)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while temp:
            print(temp.val, end=" -> ")
            temp = temp.next
        print("None")

    def deleteMiddle(self):
        solution = Solution()
        self.head = solution.deleteMiddle(self.head)

class Solution:
    def deleteMiddle(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return None
        slow = head
        fast = head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = slow.next
        return head

if __name__ == '__main__':
    # Create a linked list: 10 -> 20 -> 30 -> 40 -> 50 -> None
    llist = LinkedList()
    for val in [50, 40, 30, 20, 10]:
        llist.push(val)

    print("Original Linked List:")
    llist.printList()

    # Delete the middle node (30)
    llist.deleteMiddle()

    print("\nLinked List after deleting the middle node:")
    llist.printList()
