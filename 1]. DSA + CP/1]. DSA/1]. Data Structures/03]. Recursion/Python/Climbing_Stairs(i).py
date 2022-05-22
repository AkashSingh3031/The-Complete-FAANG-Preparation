# You are climbing a staircase. It takes n steps to reach the top.
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

# Constraints:
## 1 <= n <= 45

# Tabulation (Bottom Up)
class Solution:
    def __init__(self):
        self.ways = [0] * 46
    def climbStairs(self, n: int) -> int:
        if (n <= 2):
            return n
        self.ways[1] = 1
        self.ways[2] = 2
        for i in range(3, n + 1):
            self.ways[i] = self.ways[i - 1] + self.ways[i - 2]
        return self.ways[n]

# Time Complexity: O(N)
# Space Complexity: O(N)