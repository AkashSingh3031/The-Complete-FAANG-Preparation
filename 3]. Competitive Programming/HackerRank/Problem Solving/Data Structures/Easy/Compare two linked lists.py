
# Contributed by Paraj Shah
# https://github.com/parajshah

def compare_lists(head1, head2):        
    if not head1 or not head2:
        return '0'
    
    while head1 and head2:
        if head1.data != head2.data:
            return '0'
        head1 = head1.next
        head2 = head2.next
    
    if head1 or head2:
        return '0'    
    return '1'