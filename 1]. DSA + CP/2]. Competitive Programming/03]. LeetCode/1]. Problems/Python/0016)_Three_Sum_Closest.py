class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = float('inf')
        
        for i in range(len(nums)-2):
            j=i+1
            k=len(nums)-1
            
            while j<k:
                triple = nums[i] + nums[j] +nums[k]
                if triple == target:
                    return target
                if abs(triple-target) < abs(closest-target):
                    closest = triple
                
                if triple-target > 0:
                    k -= 1
                else:
                    j += 1
        return closest