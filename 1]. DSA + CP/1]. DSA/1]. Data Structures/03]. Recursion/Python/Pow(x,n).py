# Pow(x, n)

'''
https://leetcode.com/problems/powx-n/
'''

# Solution 1: Intuitive Recursion -- Run Time Error
'''
Function Description:
Input: x and n
Output: x to the power of the current n

Base case:
if n = 0 -> return 1
else if n = 1 -> return x
else 
    if n > 0 -> return p(x, n - 1) * x
    else -> temp = p(x, abs(n) - 1) * x
            return 1/temp
p(x, n) -> p(x, n - 1) -> p(x, n - 2) -> ... -> p(x, 1) -> p(x, 0)
'''

class Solution1:
    def myPow(self, x: float, n: int) -> float:
        # Base cases
        if (n == 0):
            return 1
        elif (n == 1):
            return x
        # Normal cases
        if (n > 0):
            return x * self.myPow(x, n - 1)
        else:
            temp_pow = x * self.myPow(x, abs(n) - 1)
            return 1 / temp_pow

# Time Complexity: O(N)
# Space Complexity: O(N)

###############################################################

# Solution 2: Optimized Recursion
'''
Function Description:
Input: x and n
Output: x to the power of the current n

If n % 2 -> temp = pow(x, n//2) -> return temp ** 2
Else -> temp = pow(x, n//2) -> return temp ** 2 * x

Base case:
if n = 0 -> return 1
else if x = 0 -> return 0
else 
    if n < 0 -> return 1 / p(x, -n)
    else -> temp = pow(x, n//2)
            if n % 2 == 0 -> return temp ** 2
            else -> return temp ** 2 * x
p(x, n) -> p(x, n/2) -> p(x, n/4) -> ... -> p(x, 0)
'''

class Solution2:
    def myPow(self, x: float, n: int) -> float:
        # Base cases
        if (n == 0):
            return 1
        elif (x == 0):
            return 0
        # Normal cases
        else:
            if (n < 0):
                return 1 / self.myPow(x, -n)
            else:
                temp = self.myPow(x, n//2)
                if (n % 2 == 0):
                    return temp * temp
                else:
                    return temp * temp * x

# Time Complexity: O(logN)
# Space Complexity: O(1)

###############################################################

# Solution 3: Intuitive Iteration -- Time Limit Exceeded
class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Edge cases
        if (n == 0):
            return 1
        elif (x in [0, 1]) or (n == 1):
            return x
        # Normal case
        res = 1
        for i in range(abs(n)):
            res *= x
        if (n > 0):
            return res
        else:
            return 1 / res

# Time Complexity: O(N)
# Space Complexity: O(1)

###############################################################

# Solution 4: Optimized Iteration
class Solution3:
    def myPow(self, x: float, n: int) -> float:
        # Edge cases
        if (n == 0):
            return 1
        elif (x in [0, 1]) or (n == 1):
            return x
        # Normal case
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

# Time Complexity: O(logN)
# Space Complexity: O(1)