#checking a palindrome or not using recursion
# ex: "peep"

def palindrome(s,b,e):
    if b>e:
        return True
    if s[b]!=s[e]:
        return False
    else:
        return palindrome(s, b+1, e-1)

s = "pop"
print(palindrome(s, 0, len(s)-1))

s = "pick"
print(palindrome(s, 0, len(s)-1))
