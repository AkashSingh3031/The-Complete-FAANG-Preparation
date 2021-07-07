class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 0:
            return None
        diff_sign = (divisor < 0) ^ (dividend < 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        result = 0
        max_divisor = divisor
        shift_count = 1
        
        while dividend >=  (max_divisor << 1):
            max_divisor <<= 1
            shift_count <<= 1
            
        while shift_count >= 1:
            if dividend >= max_divisor:
                dividend -= max_divisor
                result += shift_count
            shift_count >>= 1
            max_divisor >>= 1
        
        if diff_sign:
            result = -result
        return max(min(result, 2**31-1), -2**31)