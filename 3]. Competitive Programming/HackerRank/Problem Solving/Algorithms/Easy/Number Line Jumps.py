
# Contributed by Paraj Shah
# https://github.com/parajshah

def kangaroo(x1, v1, x2, v2):
    if x2 > x1 and v2 > v1:
        return "NO"
    for _ in range(10000):
        x1 += v1
        x2 += v2
        if x1 == x2:
            return "YES" 
    return "NO"