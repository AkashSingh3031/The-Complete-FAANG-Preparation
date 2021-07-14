class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        store = set([i for i in nums])
        start = 1
        while start in store:
            start+=1
        return start