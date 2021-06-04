# 26th Solution
#----------------------------------------------------------
from itertools import count, islice

n = int(input())
for i in range(n):
    x, prime = int(input()), True
    sq = int(x**0.5)-1
    if x<2: 
        prime = False
    else:
        for num in islice(count(2), sq):
            if not x%num:
                prime = False
    print("Prime") if prime else print("Not prime")