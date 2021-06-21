class Solution:
    
    def commonPre(self, strs, mid):
        comp = strs[0][:mid]
        for i in range(1, len(strs)):
            if comp != strs[i] [:mid]:
                return False
        return True
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        minLen = 1000000
        for a in strs:
            minLen = min(minLen, len(a))
        lo, hi = 1, minLen

        while lo <= hi:
            mid = (lo + hi) //2
            if self.commonPre(strs, mid):
                lo = mid+1
            else:
                hi = mid-1
        
        return strs[0] [: (lo+hi)//2]
