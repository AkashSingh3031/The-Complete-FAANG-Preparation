# Given an integer N, count number of its digits.
def countDigits(N):
  if N == 0:
    return 1
  if N < 0:
    N = -N
  if N >= 10:
    N //= 10
    return countDigits(N) + 1
  else:
    return 1

print(countDigits(12688))
# OUTPUT: 5
print(countDigits(375))
# OUTPUT: 3
print(countDigits(64))
# OUTPUT: 2
print(countDigits(-3459))
# OUTPUT: 4

# Time Complexity: O(logN) (Or O(log10(N)) to be exact
# Space Complexity: O(1)