class Solution:
    def isPalindrome(self, x):
        arr = str(x)
        return arr == arr[::-1]
