
# Contributed by Paraj Shah
# https://github.com/parajshah

def staircase(n):
    spaces = n
    hashes = 1
    while spaces > 0:
        print(" "*(spaces - 1),end="")
        print("#"*hashes)
        spaces -= 1
        hashes += 1
    return