class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest = ""
        centres = [len(s) - 1]
        for diff in range(1, len(s)):
            centres.append(centres[0] + diff)
            centres.append(centres[0] - diff)
            
        for centre in centres:
            if (min(centre+1, 2*len(s)-1-centre) <= len(longest)):
                break
            if centre%2 == 0:
                left, right = (centre//2)-1, (centre//2)+1
            else:
                left, right = (centre//2), (centre//2)+1
            
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
                
            if right-left-1 > len(longest):
                longest = s[left+1:right]\
            
        return longest