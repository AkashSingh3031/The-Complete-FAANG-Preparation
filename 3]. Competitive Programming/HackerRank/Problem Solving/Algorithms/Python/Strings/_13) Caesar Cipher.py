
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    k %= 26
    newString = ''
    
    for i in s:
        asciiValue = ord(i)
        # Uppercase alphabets
        if asciiValue >= 97 and asciiValue <= 122:
            if asciiValue + k > 122:
                newString += chr(96 + asciiValue - 122 + k)
            else:
                newString += chr(asciiValue + k)
        # Lowercase alphabets
        elif asciiValue >= 65 and asciiValue <= 90:
            if asciiValue + k > 90:
                newString += chr(64 + asciiValue - 90 + k)
            else:
                newString += chr(asciiValue + k)
        else:
            newString += i        
                
    return newString
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
