
# Contributed by Paraj Shah
# https://github.com/parajshah

def beautifulDays(i, j, k):
    ans = 0
    for x in range(i, j+1):
        ans += abs(not (x - int(str(x)[::-1]))%k)
    return ans