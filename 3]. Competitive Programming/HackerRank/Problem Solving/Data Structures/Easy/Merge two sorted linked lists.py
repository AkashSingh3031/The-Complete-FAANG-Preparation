
# Contributed by Paraj Shah
# https://github.com/parajshah

# Approach 1 (Iterative method)
def mergeLists(head1, head2):
    if not head1:
        return head2
    if not head2:
        return head1
    
    # Assign first element
    if head1.data <= head2.data:
        head = head1
        cur1 = head1.next
        cur2 = head2
    else:
        head = head2
        cur1 = head1
        cur2 = head2.next
        
    cur = head
    
    while True:
        # If list 1 ends, assign cur pointer to list2 and break
        if cur1 is None:
            cur.next = cur2
            break
        # If list 2 ends, assign cur pointer to list1 and break
        elif cur2 is None:
            cur.next = cur1
            break

        # Change pointers and links
        if cur1.data <= cur2.data:
            cur.next = cur1
            cur1 = cur1.next
        else:
            cur.next = cur2
            cur2 = cur2.next
        
        cur = cur.next
    return head


# Approach 2 (Recursive method)
def MergeLists(head1, head2):
  if not head1 and not head2:
    return None
  
  if head1 is None:
    return head2

  if head2 is None:
    return head1
  
  if head1.data <= head2.data:
    smallerNode = head1
    smallerNode.next = MergeLists(head1.next, head2)
  else:
    smallerNode = head2
    smallerNode.next = MergeLists(head1, head2.next)
  
  return smallerNode