class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Utility function to print the linked list
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")

# Utility function to create a linked list from a list of values
def createLinkedList(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Your solution class
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        odd = head
        even_head = even = head.next
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next
        odd.next = even_head
        return head

# Main function
if __name__ == '__main__':
    # Example: Create a linked list from [1, 2, 3, 4, 5]
    values = [1, 2, 3, 4, 5]
    head = createLinkedList(values)

    print("Original Linked List:")
    printList(head)

    # Apply odd-even transformation
    solution = Solution()
    new_head = solution.oddEvenList(head)

    print("\nLinked List after odd-even rearrangement:")
    printList(new_head)
