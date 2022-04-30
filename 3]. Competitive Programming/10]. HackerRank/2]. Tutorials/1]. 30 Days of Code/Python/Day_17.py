# 18th Solution
#------------------------------------------------------

class Calculator:
    def power(self, n, p):
        if n<0 or p<0:
            raise ValueError("n and p should be non-negative")
        return n**p
myCalculator=Calculator()
T=int(input())
for i in range(T):
    n,p = map(int, input().split())
    try:
        ans=myCalculator.power(n,p)
        print(ans)
    except Exception as e:
        print(e)   

