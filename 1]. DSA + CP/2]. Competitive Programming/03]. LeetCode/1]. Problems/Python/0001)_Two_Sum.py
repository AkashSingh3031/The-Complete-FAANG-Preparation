class Solution:
    def __init__(self,nums: list[int], target: int):
        self.nums = nums
        self.target = target

    # def twoSum(self) 
    #     num_to_index = {}
        
    #     for i, num in enumerate(self.nums):
    #         if self.target-num in num_to_index:
    #             return [num_to_index[self.target-num], i]
    #         num_to_index[num] = i
    #     return []
    
    def twoNumberSum(self) -> list[int]:
        for i in range(len(self.nums)-1):
            firstNum = self.nums[i]
            for j in range(i+1,len(self.nums)):
                secondNum = self.nums[j]
                if firstNum+secondNum == self.target:
                    return [firstNum,secondNum]
        return []

sol1 = Solution([2,5,3,6,9,-2], 8)
# print(sol1.twoSum())
print(sol1.twoNumberSum())
