
# Contributed by Paraj Shah
# https://github.com/parajshah

def repeatedString(s, n):
    return s.count("a") * (n // len(s)) + s[:n % len(s)].count("a")