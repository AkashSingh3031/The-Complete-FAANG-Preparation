from typing import List

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

# Main function to test the solution
if __name__ == '__main__':
    solution = Solution()

    # Example test cases
    test_cases = [
        [2, 4, 1, 1, 6, 5],       # Expected output: 3 (hill at 4, valley at 1, hill at 6)
        [6, 6, 6],                # Expected output: 0 (flat line)
        [1, 2, 3, 4, 5],          # Expected output: 0 (strictly increasing)
        [5, 4, 3, 2, 1],          # Expected output: 0 (strictly decreasing)
        [1, 3, 2, 4, 1],          # Expected output: 3 (hill at 3, valley at 2, hill at 4)
        [1, 2, 2, 3, 2, 2, 1],    # Expected output: 2 (hill at 3, valley at 2)
    ]

    for i, nums in enumerate(test_cases, 1):
        result = solution.countHillValley(nums)
        print(f"Test Case {i}: {nums} → Hills & Valleys = {result}")
