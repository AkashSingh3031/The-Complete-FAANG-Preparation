class Solution:
    def romanToInt(self, s: str) -> int:
        doubles = {'CM':900, 'CD':400, 'XC':90, 'XL':40, 'IX':9, 'IV':4}
        singles = {'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}
        
        integer = 0
        i=0
        
        while i < len(s):
            if i < len(s) - 1 and s[i:i+2] in doubles:
                integer += doubles[s[i:i+2]]
                i += 2
            else:
                integer += singles[s[i]]
                i += 1
        return integer