
# Contributed by Paraj Shah
# https://github.com/parajshah

def reverse(head):
    if not head:
        return head
    head.next, head.prev = head.prev, head.next
    if not head.prev:
        return head
    return reverse(head.prev)