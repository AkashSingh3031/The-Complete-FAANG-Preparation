# 1st Solution
from statistics import median
n = int(input())
arr = [int(x) for x in input().split()]
arr.sort()
t = int(len(arr)/2)
if len(arr)%2 == 0:
    L = arr[:t]
    U = arr[t:]

else:
    L = arr[:t]
    U = arr[t+1:]

print(int(median(L)))
print(int(median(arr)))
print(int(median(U)))

# 2nd Solution
import statistics as st
n = int(input())
data = list(map(int, input().split()))
freq = list(map(int, input().split()))

s = []
for i in range(n):
    s += [data[i]] * freq[i]

N = sum(freq)
s.sort()

if n%2 != 0:
    q1 = st.median(s[:N//2])
    q3 = st.median(s[N//2+1:])
else:
    q1 = st.median(s[:N//2])
    q3 = st.median(s[N//2:])

ir = round(float(q3-q1), 1)
print(ir)


# 3rd Solution
n = int(input().strip())
X = [int(x) for x in input().strip().split()]

mean = sum(X)/n
variance = sum([((x - mean) ** 2) for x in X])/n
stddev = variance ** 0.5
print("{0:0.1f}".format(stddev))
