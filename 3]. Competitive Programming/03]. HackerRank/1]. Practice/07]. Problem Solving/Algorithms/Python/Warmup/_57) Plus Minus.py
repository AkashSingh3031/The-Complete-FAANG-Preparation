
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    c_pos = 0
    c_neg = 0
    c_zero = 0
    for i in range(len(arr)):
        if arr[i] > 0:
            c_pos += 1
        if arr[i] < 0:
            c_neg += 1
        if arr[i] == 0:
            c_zero += 1
    
    print(c_pos / len(arr))
    print(c_neg / len(arr))
    print(c_zero / len(arr))
    return


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
