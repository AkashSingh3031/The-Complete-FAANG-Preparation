# Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
def myPow(x: float, n: int):
    
    if (n == 0):
        return 1
    elif (x == 0):
        return 0
    
    else:
        if (n < 0):
            return 1 / myPow(x, -n)
        else:
            temp = myPow(x, n//2)
            if (n % 2 == 0):
                return temp * temp
            else:
                return temp * temp * x

print(myPow(2.00000, 10))
# OUTPUT: 1024.0
print(myPow(2.10000, 3))
# OUTPUT: 9.261000000000001
print(myPow(2.00000, -2))
# OUTPUT: 0.25

# Time Complexity: O(logN)
# Space Complexity: O(1)