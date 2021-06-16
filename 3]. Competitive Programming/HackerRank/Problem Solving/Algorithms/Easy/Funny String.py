
# Contributed by Paraj Shah
# https://github.com/parajshah

def funnyString(s):
    # Find ascii values for string
    asciiValues = []
    for i in s:
        asciiValues.append(ord(i))
    
    # Find ascii values for reverse of string (same as reversing the array)
    asciiValuesReverse = []
    for i in range(len(asciiValues)):
        asciiValuesReverse.append(asciiValues[len(asciiValues) - i - 1])
        
    # Compare the 2 arrays
    for i in range(len(s) - 1):
        if abs(asciiValues[i + 1] - asciiValues[i]) != abs(asciiValuesReverse[i + 1] - asciiValuesReverse[i]):
            return "Not Funny"
    return "Funny"