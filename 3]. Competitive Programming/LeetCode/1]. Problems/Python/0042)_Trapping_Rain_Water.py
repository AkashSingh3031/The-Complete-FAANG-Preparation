class Solution:
    def trap(self, height: List[int]) -> int:
        waterLevel = []
        left = 0
        for h in height:
            left = max(left, h) 
            waterLevel += [left] 
        right = 0
        for i, h in reversed(list(enumerate(height))):
            right = max(right, h)
            waterLevel[i] = min(waterLevel[i], right) - h 
        return sum(waterLevel)