
# Contributed by Paraj Shah
# https://github.com/parajshah

def getNode(head, positionFromTail):
    i = 0
    cur = head
    result = head
    
    while cur:
        cur = cur.next
        if i > positionFromTail:
            result = result.next
        i += 1
        
    return result.data