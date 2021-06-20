
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'funnyString' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

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

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = funnyString(s)

        fptr.write(result + '\n')

    fptr.close()
