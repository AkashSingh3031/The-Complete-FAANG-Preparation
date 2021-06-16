
# Contributed by Paraj Shah
# https://github.com/parajshah

def jumpingOnClouds(c, k):
    energy, pos = 100, 0
    n = len(c)
    while True:
        pos = (pos + k) % n
        if pos == 0:
            if c[pos] == 1:
                return energy - 3                
            return energy - 1
        else:
            if c[pos] == 1:
                energy -= 3
            else:
                energy -= 1
        if energy == 0:
            break