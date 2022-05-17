class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        next_new = 0
        for i in range(len(nums)):
            if i==0 or nums[i] != nums[i-1]:
                nums[next_new] = nums[i]
                next_new += 1
        return next_new