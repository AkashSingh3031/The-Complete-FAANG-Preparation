# Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
def myPow(x, n):

    if (n == 0):
        return 1
    elif (x in [0, 1]) or (n == 1):
        return x

    res = 1
    if (n < 0):
        x = 1 / x
        n = - (n + 1)
        res *= x
    while n > 0:
        if (n % 2): # n is odd
            res *= x
            n -= 1
        else: # jump 2 steps when n is even
            x *= x
            n //= 2
    return res

print(myPow(2.00000, 10))
# OUTPUT: 1024.0
print(myPow(2.10000, 3))
# OUTPUT: 9.261000000000001
print(myPow(2.00000, -2))
# OUTPUT: 0.25

# Time Complexity: O(logN)
# Space Complexity: O(1)
