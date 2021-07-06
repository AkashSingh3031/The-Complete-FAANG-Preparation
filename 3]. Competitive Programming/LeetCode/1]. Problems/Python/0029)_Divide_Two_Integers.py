class Solution:
    def divide(self, dividend, divisor):
        ans = 0
        pos = [abs(divisor)]
        cnts = [1]
        n = 0
        while pos and n <= abs(dividend):
            if n + pos[-1] + pos[-1] <= abs(dividend):
                pos.append(pos[-1] + pos[-1])
                cnts.append(cnts[-1] + cnts[-1])
                ans += cnts[-1]
                n += pos[-1]
            elif n + pos[-1] <= abs(dividend):
                ans += cnts[-1]
                n += pos[-1]
            else:
                while pos:
                    if n + pos[-1] <= abs(dividend):
                        ans += cnts[-1]
                        n += pos[-1]
                    else:
                        pos.pop()
                        cnts.pop()
        if dividend > 0 and divisor < 0 or dividend < 0 and divisor > 0:
            ans = -ans
        if ans < -(2**31) or ans > 2**31 - 1:
            return 2**31 - 1
        return ans
