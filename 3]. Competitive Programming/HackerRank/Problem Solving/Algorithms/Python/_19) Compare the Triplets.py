
# Contributed by Paraj Shah
# https://github.com/parajshah

def compareTriplets(a, b):
    alice,bob = 0,0
    for i in range(len(a)):
        if a[i] > b[i]:
            alice += 1
        elif a[i] < b[i]:
            bob += 1

    return alice,bob