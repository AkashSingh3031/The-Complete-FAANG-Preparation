class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen = {}
        start = longest = 0
        
        for i, c in enumerate(s):
            if c in last_seen and last_seen[c] >= start:
                start = last_seen[c] + 1
            else:
                longest = max(longest, i - start + 1)
            
            last_seen[c] = i
        return longest