
# Contributed by Paraj Shah
# https://github.com/parajshah

def divisibleSumPairs(n, k, a):
    count = 0
    for i in range(len(a)):
        SUM = 0
        for j in range(i+1,len(a)):
            if i < j:
                SUM = a[i] + a[j]
                if SUM % k == 0:
                    count += 1
    return count