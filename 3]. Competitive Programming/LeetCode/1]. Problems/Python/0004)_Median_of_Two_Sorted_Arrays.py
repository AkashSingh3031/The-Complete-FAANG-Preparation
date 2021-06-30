class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def get_kth_smallest(num1_start, num2_start, k):
            if k <= 0 or k > len(nums1) - num1_start + len(nums2) - num2_start:
                raise ValueError('K is out of bounds of input lists')
                
            if num1_start >= len(nums1):
                return nums2[num2_start + k - 1]
            if num2_start >= len(nums2):
                return nums1[num1_start + k - 1]
            if k == 1:
                return min(nums1[num1_start], nums2[num2_start])
            
            mid_num1, mid_num2 = float('inf'), float('inf')
            if k//2 - 1 < len(nums1) - num1_start:
                mid_num1 = nums1[num1_start + k//2 - 1]
            if k//2 - 1 < len(nums2) - num2_start:
                mid_num2 = nums2[num2_start + k//2 - 1]
                
            if mid_num1 < mid_num2:
                return get_kth_smallest(num1_start + k//2, num2_start, k - k//2)
            return get_kth_smallest(num1_start, num2_start + k//2, k - k//2)
        
        right = get_kth_smallest(0, 0, 1+ (len(nums1)+len(nums2)) // 2)
        if (len(nums1) + len(nums2)) % 2 == 1:
            return right
        
        left = get_kth_smallest(0, 0, (len(nums1)+len(nums2)) // 2)
        return (left + right)/2.0