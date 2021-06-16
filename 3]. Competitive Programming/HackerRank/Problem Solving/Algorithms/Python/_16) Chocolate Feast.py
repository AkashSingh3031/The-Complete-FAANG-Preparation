
# Contributed by Paraj Shah
# https://github.com/parajshah

def chocolateFeast(n, c, m):
    count = n//c
    x = count
    while x>=m:
        a,b = divmod(x,m)
        count += a
        x = a + b
    return count