
# Contributed by Paraj Shah
# https://github.com/parajshah

def pickingNumbers(a):
    maximum = 0
    for i in a:
        c = a.count(i)
        d = a.count(i - 1)
        c = c + d
        if c > maximum:
            maximum = c
    return maximum