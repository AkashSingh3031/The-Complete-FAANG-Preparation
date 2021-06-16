
# Contributed by Paraj Shah
# https://github.com/parajshah

from collections import deque 

def circularArrayRotation(a, k, queries):
    items = deque(a) 
    items.rotate(k)
    ret_list = []
    for q in queries:
        ret_list.append(items[q])
    return ret_list