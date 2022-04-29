class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        for i in str(bin(n)):
            if(i == '1'):
                count = count + 1
        return count