
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'migratoryBirds' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def migratoryBirds(arr):
    # Write your code here
    counts = {}
    for i in arr:
        if i in counts:
            counts[i] += 1
        else:
            counts[i] = 1
    print(counts)
    m = max(counts.values())
    minKey = 100000
    for key, value in counts.items():
        if value == m:
            if minKey > key:
                minKey = key
                
    return minKey

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
