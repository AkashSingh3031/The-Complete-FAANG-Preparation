from insertion import node

def push(head_ref, newdata):
    new_node = node(newdata)
    new_node.data = newdata
    new_node.next = head_ref
    head_ref = new_node
    return head_ref

def prList(node):
    while (node != None):
        print(node.data, end = " ")
        node = node.next

def countRotation(head):
    count = 0

    min = head.data

    while head:
        if head.data < min:
            break
        count += 1
        head = head.next

    return count


head = None

head = push(head, 12)
head = push(head, 11)
head = push(head, 8)
head = push(head, 5)
head = push(head, 18)
head = push(head, 15)

prList(head);
print()
print("Linked list rotated elements: ",
        end = '')

print(countRotation(head))