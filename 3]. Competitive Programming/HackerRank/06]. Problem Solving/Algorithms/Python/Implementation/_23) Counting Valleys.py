
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    valley_count = 0
    sea_level = 0
    current_pos = 0
    for i in range(n):
        if s[i] == "U":
            current_pos += 1
            if current_pos == sea_level:
                valley_count += 1
        else:
            current_pos -= 1
            
    return valley_count
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
