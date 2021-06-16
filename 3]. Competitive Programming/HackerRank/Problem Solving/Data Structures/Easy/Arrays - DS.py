
# Contributed by Paraj Shah
# https://github.com/parajshah

def reverseArray(a):
    new_arr = list()
    i = len(a)
    while i > 0:
        new_arr.append(a[i-1])
        i -= 1
    return new_arr



# Alternate Solution
# def reverseArray(a):
#     a.reverse()
#     return a