class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        next_free = 0
        for i, num in enumerate(nums):
            if num != val:
                nums[next_free] = num
                next_free += 1
        return next_free