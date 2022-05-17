from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s):
        d = defaultdict()
        max_len = 0
        cur = ''
        for i in range(len(s)):
            if s[i] in d:
                max_len = max(max_len, len(cur))
                c = 0
                while cur[c] != s[i]:
                    del d[cur[c]]
                    c += 1
                cur = cur[c+1:]
            cur += s[i]
            d[s[i]] = i
        if cur:
            max_len = max(max_len, len(cur))
        return max_len
