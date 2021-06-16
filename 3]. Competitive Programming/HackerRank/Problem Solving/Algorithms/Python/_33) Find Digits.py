
# Contributed by Paraj Shah
# https://github.com/parajshah

def findDigits(n):
    temp = n
    count = 0
    while n > 0:
        d = n % 10
        n //= 10
        if d == 0:
            continue
        if temp % d == 0:
            count += 1        
    return count