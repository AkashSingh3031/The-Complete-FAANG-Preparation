
# Contributed by Paraj Shah
# https://github.com/parajshah

def birthday(s, d, m):
    possibleCount = 0
    for i in range(len(s)):
        SUM = 0
        count = 0
        for j in range(i,len(s)):
            SUM += s[j]
            count += 1
            if SUM > d:
                break
            if count == m and SUM == d:
                possibleCount += 1
                break
    return possibleCount