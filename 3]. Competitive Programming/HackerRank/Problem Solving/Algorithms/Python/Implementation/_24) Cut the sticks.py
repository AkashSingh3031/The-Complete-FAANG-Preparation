
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque

# Complete the cutTheSticks function below.
def cutTheSticks(arr):
    ls = []
    while len(arr) >= 1:
        ls.append(len(arr))
        minn = min(arr)
        arr = [i-minn for i in arr if i!=minn]
    return ls


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = cutTheSticks(arr)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
