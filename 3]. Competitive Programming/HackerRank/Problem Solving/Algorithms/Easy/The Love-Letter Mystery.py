
# Contributed by Paraj Shah
# https://github.com/parajshah

def theLoveLetterMystery(s):
    answer = 0
    for i in range(len(s) // 2):
        diff = abs(ord(s[i]) - ord(s[len(s) - i - 1]))
        answer += diff
    return answer