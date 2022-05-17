from insertion import linkedList, node

def compare(list1, list2):
    while list1 and list2 and list1.data == list2.data:
        list1 = list1.next
        list2 = list2.next

    if list1 and list2:
        return 1 if list1.data > list2.data else -1
    
    if list1 and not list2:
        return 1
    
    if list2 and not list1:
        return -1

    return 0
                
list1 = node('g')
list1.next = node('e')
list1.next.next = node('e')
list1.next.next.next = node('k')
list1.next.next.next.next = node('s')
#list1.next.next.next.next.next = node('a')

list2 = node('g')
list2.next = node('e')
list2.next.next = node('e')
list2.next.next.next = node('k')
list2.next.next.next.next = node('s')
list2.next.next.next.next.next = node('b')

print(compare(list1, list2))