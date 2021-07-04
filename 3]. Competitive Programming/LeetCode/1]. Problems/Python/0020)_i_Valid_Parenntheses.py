class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        match = {'(':')', '[':']', '{':'}'}
        
        for c in s:
            if c in match:
                stack.append(c)
            else:
                if not stack or match[stack.pop()] != c:
                    return False
        return not stack