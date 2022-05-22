# You are climbing a staircase. It takes n steps to reach the top.
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

# Constraints:
## 1 <= n <= 45

# Memoization (Top Down)
class Solution:
    def __init__(self):
        self.ways = [0] * 46
    def climbStairs(self, n: int) -> int:
        if (n <= 2):
            return n
        elif self.ways[n] != 0:
            return self.ways[n]
        else:
            self.ways[n] = self.climbStairs(n - 1) + self.climbStairs(n - 2)
            return self.ways[n]

# Time Complexity: O(N)
# Space Complexity: O(N)