
# Contributed by Paraj Shah
# https://github.com/parajshah

def saveThePrisoner(n, m, s):
    m %= n
    s += m - 2
    return 1 + (s % n)