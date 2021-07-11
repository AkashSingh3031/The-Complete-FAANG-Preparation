class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        
        while left <= right:
            mid = (left+right)//2
            if nums[mid] == target:
                return mid
            if nums[left] <= nums[mid]:
                if target  >= nums[left] and target < nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
            else:
                if target <= nums[right] and target > nums[mid]:
                    left = mid+1
                else:
                    right = mid-1
        return -1