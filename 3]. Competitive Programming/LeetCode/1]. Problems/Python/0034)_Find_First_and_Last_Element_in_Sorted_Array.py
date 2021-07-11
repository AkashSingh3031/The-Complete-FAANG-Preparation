class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binary(target, left, right):
            if left > right:
                return left
            mid = (left+right)//2
            if target > nums[mid]:
                left = mid+1
            else:
                right = mid-1
            return binary(target, left, right)
        lower = binary(target-0.5, 0, len(nums)-1)
        upper = binary(target+0.5, 0, len(nums)-1)
        return [-1, -1] if lower == upper else [lower, upper-1]