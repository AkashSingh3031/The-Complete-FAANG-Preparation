# 1st Solution
import numpy as np
from scipy import stats

size = int(input())
numbers = list(map(int, input().split()))

print(np.mean(numbers))
print(np.median(numbers))
print(int(stats.mode(numbers)[0]))



# 2nd Solution
import operator
input()
n = list(map(int, input().split()))
w = list(map(int, input().split()))
print('{0:.1f}'.format(sum(map(operator.mul, n, w))/sum(w)))
