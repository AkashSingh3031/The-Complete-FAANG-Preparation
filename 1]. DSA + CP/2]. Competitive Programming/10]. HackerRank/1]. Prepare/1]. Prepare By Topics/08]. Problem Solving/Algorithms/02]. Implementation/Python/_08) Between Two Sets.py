
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def getTotalX(a, b):
    # Write your code here
    x = max(a)
    count = 0
    y = min(b)
    
    for i in range(x,y+1):
        for j in range(len(a)):
            # Check if number is multiple of all elements in array a
            if not i % a[j] == 0:
                break
            # If YES..
            if j == len(a) - 1:
                # Check if number is factor of all elements in array b
                for k in range(len(b)):
                    if not b[k] % i == 0:
                        break
                    # If YES..
                    if k == len(b) - 1:
                        count += 1       
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()
