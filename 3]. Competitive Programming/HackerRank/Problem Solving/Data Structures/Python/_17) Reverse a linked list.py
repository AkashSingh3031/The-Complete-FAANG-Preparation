
# Contributed by Paraj Shah
# https://github.com/parajshah

def reverse(head):
    prevPointer = None
    currentPointer = head
    while currentPointer is not None:
        # Assigning nextPointer to next of currentPointer
        nextPointer = currentPointer.next
        # Reversing the connection
        currentPointer.next = prevPointer
        # Incrementing prevPointer
        prevPointer = currentPointer
        # Incrementing currentPointer
        currentPointer = nextPointer
        
    head = prevPointer
    return head