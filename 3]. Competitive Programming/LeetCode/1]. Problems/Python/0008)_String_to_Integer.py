class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        negative = False
        if str and str[0] == '-':
            negative = True
        if str and (str[0 ] == '+' or str[0] == '-'):
            str = str[1:]
        if not str:
            return 0
        
        digits = {i for i in '0123456789'}
        result = 0
        for c in str:
            if c not in digits:
                break
            result = result*10 +int(c)
            
        if negative:
            result = -result
            
        result = max(min(result, 2**31-1), -2**31)
        return result