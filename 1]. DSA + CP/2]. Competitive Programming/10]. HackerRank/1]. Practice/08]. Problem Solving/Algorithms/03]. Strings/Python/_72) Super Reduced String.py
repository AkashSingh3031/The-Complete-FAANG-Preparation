
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superReducedString' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def superReducedString(s):
    stringList = list(s)
    i = 0
    while i < len(stringList) - 1:
        if stringList[i] == stringList[i + 1]:
            del stringList[i]
            del stringList[i]
            i = 0
            if len(stringList) == 0:
                return('Empty String')
        else:
            i += 1
    return "".join(stringList)    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = superReducedString(s)

    fptr.write(result + '\n')

    fptr.close()
