
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the staircase function below.
def staircase(n):
    spaces = n
    hashes = 1
    while spaces > 0:
        print(" "*(spaces - 1),end="")
        print("#"*hashes)
        spaces -= 1
        hashes += 1
    return

if __name__ == '__main__':
    n = int(input())

    staircase(n)
