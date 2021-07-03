class Solution:
<<<<<<< HEAD
    def maxArea(self, height: List[int]) -> int:
        left=0
        right = len(height)-1
        max_area = (right-left)*min(height[right], height[left])
        
        while left < right:
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
            max_area = max(max_area, (right-left)*min(height[right], height[left]))
        return max_area
=======
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
>>>>>>> 31712a68b582919c9d6372dd6170cc2c50c580ff
