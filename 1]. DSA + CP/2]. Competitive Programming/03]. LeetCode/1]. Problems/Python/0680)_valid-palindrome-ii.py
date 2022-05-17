class Solution:
    
    def validPalindrome(self, s: str) -> bool:
        def checkPali(s,st,end):
            while(st < end):
                if(s[st] == s[end]):
                    st = st + 1
                    end = end - 1
                else:
                    return False
            return True 
        st = 0
        end = len(s)-1
        while(st < end):
            if(s[st] == s[end]):
                st = st + 1
                end = end - 1
            else:
                return checkPali(s,st+1,end) or checkPali(s,st,end-1)

        return True