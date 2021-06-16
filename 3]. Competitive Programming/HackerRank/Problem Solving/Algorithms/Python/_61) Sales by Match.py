
# Contributed by Paraj Shah
# https://github.com/parajshah

def sockMerchant(n, a):
    flags = [0] * n
    count = 0
    for i in range(n):
        for j in range(i+1,n):
            if a[i] == a[j] and (flags[i] != 1 and flags[j] != 1) :
                flags[i] = 1
                flags[j] = 1
                count += 1
    return count