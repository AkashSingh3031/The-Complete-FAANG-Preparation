
# Contributed by Paraj Shah
# https://github.com/parajshah

def pangrams(s):
    alphabets = [0] * 26
    for i in s:
        if i.isalpha():
            index = ord(i.lower()) - ord('a')
            alphabets[index] += 1
    
    for i in alphabets:
        if i == 0:
            return "not pangram"
    return "pangram"