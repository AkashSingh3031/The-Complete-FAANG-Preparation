
# Contributed by Paraj Shah
# https://github.com/parajshah

def countingValleys(n, s):
    valleyCount, seaLevel, currentPosition = 0,0,0
    for i in range(n):
        if s[i] == "U":
            currentPosition += 1
            if currentPosition == seaLevel:
                valleyCount += 1
        else:
            currentPosition -= 1
            
    return valleyCount