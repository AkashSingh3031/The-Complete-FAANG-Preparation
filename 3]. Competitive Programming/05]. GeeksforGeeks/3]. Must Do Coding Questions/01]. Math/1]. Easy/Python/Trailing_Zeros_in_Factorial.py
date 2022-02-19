class Solution:
    def trailingZeroes(self, N):
        #code here 
        if(N<0):
            return -1
        count = 0
        i=5
        while (N//i)>=1:
            count += N//i
            i *= 5
        return count

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N = int(input()) 
        ob = Solution()
        ans = ob.trailingZeroes(N)
        print(ans)
