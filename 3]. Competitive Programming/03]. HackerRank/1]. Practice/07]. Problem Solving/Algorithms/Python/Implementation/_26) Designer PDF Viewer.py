
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the designerPdfViewer function below.
def designerPdfViewer(h, word):
    height = 0
    for c in word:
        height = max(height, h[ord(c) - ord("a")])
    return height * len(word)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = list(map(int, input().rstrip().split()))

    word = input()

    result = designerPdfViewer(h, word)

    fptr.write(str(result) + '\n')

    fptr.close()
