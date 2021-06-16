
# Contributed by Paraj Shah
# https://github.com/parajshah

def appendAndDelete(s, t, k):
    l = len(s)
    c = 0
    while s[:l] != t[:l]:
        l -= 1
        c += 1
    o = (len(t) - l) + c
    if k < o:
        return "No"
    elif (len(s) + len(t)) <= k:
        return "Yes"
    elif 2 * len(t) < k:
        return "Yes"
    elif k % 2 == o % 2:
        return "Yes"
    return "No"