
# Contributed by Paraj Shah
# https://github.com/parajshah

def extraLongFactorials(n):
    fact = 1
    while n > 0:
        fact *= n
        n -= 1
    print(fact)