
# Contributed by Paraj Shah
# https://github.com/parajshah

def countApplessAndOranges(s, t, a, b, apples, oranges):
    countApples = 0
    countOranges = 0
    for i in range(len(apples)):
        if a + apples[i] in range(s,t+1):
            countApples += 1
    print(countApples)

    for i in range(len(oranges)):
        if b + oranges[i] in range(s,t+1):
            countOranges += 1
    print(countOranges)