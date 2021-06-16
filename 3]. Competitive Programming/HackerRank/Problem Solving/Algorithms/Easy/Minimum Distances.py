
# Contributed by Paraj Shah
# https://github.com/parajshah

def minimumDistances(a):
    d = []
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i] == a[j]:
                d.append(abs(i - j))
    if len(d) == 0:
        return -1
    d.sort()
    return d[0]