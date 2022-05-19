# Write a function that reverses a string. The input string is given as an array of characters s.
def reverseString(s) -> None:

    left = 0
    right = len(s) - 1
    
    def recursiveReverse(l, r):
        
        if l == r or l > r:
            return
        
        s[l], s[r] = s[r], s[l]
        return recursiveReverse(l + 1, r - 1)
    recursiveReverse(left, right)
    return s

print(reverseString(["h","e","l","l","o"]))
# OUTPUT: ['o', 'l', 'l', 'e', 'h']
print(reverseString(["H","a","n","n","a","h"]))
# OUTPUT: ['h', 'a', 'n', 'n', 'a', 'H']

# Time Complexity: O(n)
# Space Complexity: O(N) to maintain the recursion stack