class Solution:
    #strs is a list of strings
    #mid is the endpos of substring to be checked
    #returns True if strs[0: mid] is a common prefix, false otherwise
    def commonPre(self, strs, mid):
        comp = strs[0][:mid]
        for i in range(1, len(strs)):
            if comp != strs[i] [:mid]:
                return False
        return True
    
    #strs is a list of str
    #returns str which is the largest common prefix
    def longestCommonPrefix(self, strs):
        minLen = 1000000
        #looking for minLen from all strings in the list as the common prefix can be at max the full length as the shortest string
        for a in strs:
            minLen = min(minLen, len(a))
        lo, hi = 1, minLen
        
        #using binary search to find the common prefix
        while lo <= hi:
            mid = (lo + hi) //2
            if self.commonPre(strs, mid):
                lo = mid+1
            else:
                hi = mid-1
        
        return strs[0] [: (lo+hi)//2]
