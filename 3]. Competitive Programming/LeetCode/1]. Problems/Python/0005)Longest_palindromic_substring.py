class Solution:
   #S is a string
    def longestPalindrome(self, s):
       
        long, beg = 1, 0
        n = len(s)
        dp = [[None]*n for _ in range(n)]
        for i in range(len(s)):
            dp[i][i] = True
        
        for k in range(2, len(s) + 1):
            for j in range(len(s) - k + 1):
            
                if s[j] != s[j+k-1]:
                    dp[j] [j+k-1] = False
                else:
                    if k <= 2:
                        dp[j] [j+k-1] = True
                    else:
                        dp[j] [j+k-1] = dp[j+1] [j+k-2]
                    
                    if dp[j] [j+k-1]:
                        if k > long:
                            long = k
                            beg = j
                        
                            
        return s[beg:beg+long]
                            
