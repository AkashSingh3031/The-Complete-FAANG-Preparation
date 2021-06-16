
# Contributed by Paraj Shah
# https://github.com/parajshah

def reversePrint(head):
    if head:
        reversePrint(head.next)
        print(head.data)
    else:
        return