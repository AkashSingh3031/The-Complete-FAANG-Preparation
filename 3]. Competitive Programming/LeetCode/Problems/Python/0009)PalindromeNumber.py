class Solution:
    def isPalindrome(self, x: int) -> bool:
        arr = str(x)
        return arr == arr[::-1]