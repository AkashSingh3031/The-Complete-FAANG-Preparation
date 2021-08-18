class Solution:
    def MissingNumber(self,array,n):
        # code here
        total = n*(n+1)//2
        s=0
        for i in range(n-1):
            s += array[i]
        return total-s;

t=int(input())
for _ in range(0,t):
    n=int(input())
    a=list(map(int,input().split()))
    s=Solution().MissingNumber(a,n)
    print(s)
