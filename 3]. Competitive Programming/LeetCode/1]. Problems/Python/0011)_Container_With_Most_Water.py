class Solution:
    def maxArea(self, height):
        i = 0
        j = len(height) - 1
        start = height[i]
        end = height[j]
        ans = min(start, end) * (j - i)
        while i < j:
            if start <= end:
                while i < j:
                    i += 1
                    if height[i] > start:
                        start = height[i]
                        ans = max(ans, min(start, end) * (j - i))
                        break
            elif end < start:
                while j > i:
                    j -= 1
                    if height[j] > end:
                        end = height[j]
                        ans = max(ans, min(start, end) * (j - i))
                        break
        return ans
