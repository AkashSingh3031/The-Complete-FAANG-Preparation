from collections import Counter
class Solution:
    # @param A : tuple of integers
    # @return an integer
    def repeatedNumber(self, A):
        c=Counter(A)
        for i in c:
            if(c[i]>1):
                return i
        return -1
