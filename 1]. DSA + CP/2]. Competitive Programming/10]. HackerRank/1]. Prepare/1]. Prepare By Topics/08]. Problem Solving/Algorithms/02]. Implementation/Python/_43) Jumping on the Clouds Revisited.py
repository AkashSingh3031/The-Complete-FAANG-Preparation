
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c, k):
    energy = 100
    pos = 0
    n = len(c)
    while True:
        pos = (pos + k) % n
        #print(energy,pos)
        if pos == 0:
            if c[pos] == 1:
                return energy - 3                
            return energy - 1
        else:
            if c[pos] == 1:
                energy -= 3
            else:
                energy -= 1
        if energy == 0:
            break

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c, k)

    fptr.write(str(result) + '\n')

    fptr.close()
