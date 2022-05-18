class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        #using two pointers
        st = 0 
        end = len(s)-1
        while(end>st):
            tp1=s[st]
            tp2=s[end]
        
            s[st]=tp2
            s[end]=tp1
        
            st = st+1
            end = end-1