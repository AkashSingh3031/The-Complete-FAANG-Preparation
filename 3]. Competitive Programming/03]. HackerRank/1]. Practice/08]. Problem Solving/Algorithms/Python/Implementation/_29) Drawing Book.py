
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import os
import sys

#
# Complete the pageCount function below.
#
def pageCount(n, p):
    # p -> page to be turned to
    # n -> number of pages in book
    if(p <= n):
        return min(p // 2, n // 2 - p // 2)    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    p = int(input())

    result = pageCount(n, p)

    fptr.write(str(result) + '\n')

    fptr.close()
