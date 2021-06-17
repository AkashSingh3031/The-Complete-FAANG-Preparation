
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'insertionSort1' function below.
#
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY arr
#

def insertionSort1(n, arr):
    lastElement = arr[-1]
    
    for i in range(len(arr) - 1, -1, -1):
        if arr[i - 1] >= lastElement and i != 0:
            arr[i] = arr[i - 1]
            print(*arr)
        else:
            arr[i] = lastElement
            print(*arr)
            return
        
        

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    insertionSort1(n, arr)
