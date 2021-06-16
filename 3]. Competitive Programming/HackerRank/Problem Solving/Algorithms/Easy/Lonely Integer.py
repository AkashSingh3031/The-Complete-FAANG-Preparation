
# Contributed by Paraj Shah
# https://github.com/parajshah

# Using in-built count()
# def lonelyinteger(a):
#     for i in a:
#         if a.count(i) == 1:
#             return i

# Using bit manipulation (XOR)
def lonelyinteger(a):
    answer = 0
    for i in a:
        answer ^= i
    return answer