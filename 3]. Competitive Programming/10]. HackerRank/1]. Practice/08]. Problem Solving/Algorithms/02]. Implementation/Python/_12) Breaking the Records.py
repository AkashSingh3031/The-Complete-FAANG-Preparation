
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the breakingRecords function below.
def breakingRecords(scores):
    minimum = scores[0]
    maximum = scores[0]
    count_min = 0
    count_max = 0
    for i in range(1,len(scores)):
        if scores[i] < minimum:
            minimum = scores[i]
            count_min += 1
        if scores[i] > maximum:
            maximum = scores[i]
            count_max += 1
    return count_max,count_min

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
