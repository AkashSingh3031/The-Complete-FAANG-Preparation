class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        count = 0
        prev = nums[0]
        i = 1
        while i < len(nums) - 1:
            cur = nums[i]
            k = i + 1
            while k < len(nums) and nums[k] == cur:
                k += 1
            if k >= len(nums):
                break
            right = nums[k]
            if cur != prev:
                if cur > prev and cur > right:
                    count += 1
                elif cur < prev and cur < right:
                    count += 1
                prev = cur
            i = k

        return count
