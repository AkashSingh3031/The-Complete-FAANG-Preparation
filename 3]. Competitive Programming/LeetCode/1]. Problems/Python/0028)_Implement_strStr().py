class Solution:
    def strStr(self, haystack, needle):
        if needle == '':
            return 0
        if haystack == '' or needle not in haystack:
            return -1
        else:
            return haystack.index(needle)
