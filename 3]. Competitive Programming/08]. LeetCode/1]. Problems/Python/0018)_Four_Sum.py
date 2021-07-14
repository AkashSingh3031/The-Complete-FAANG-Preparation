class Solution:
    ELEMENTS = 4
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        results = []
        self.n_sum(sorted(nums), target, [], self.ELEMENTS, results)
        return results
    
    def n_sum(self, nums, target, partial, n, results):
        if len(nums) < n or target > nums[-1]*n or target < nums[0]*n:
            return
        
        if n == 2:
            left = 0
            right = len(nums) - 1
            while left < right:
                if nums[left] + nums[right] == target:
                    results.append(partial + [nums[left], nums[right]])
                    left += 1
                    right -= 1
                    
                    while nums[right] == nums[right+1] and right > left:
                        right -= 1
                elif nums[left] + nums[right] < target:
                    left += 1
                else:
                    right -= 1
        else:
            for i in range(len(nums) - n+1):
                if i == 0 or nums[i] != nums[i-1]:
                    self.n_sum(nums[i+1:], target-nums[i], partial+[nums[i]], n-1, results)