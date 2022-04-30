
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the bonAppetit function below.
def bonAppetit(bill, k, b):
    b_actual = 0
    b_charged = b
    for i in range(len(bill)):
        if i == k:
            continue
        else:
            b_actual += bill[i]
    b_actual = b_actual // 2
    
    print("Bon Appetit" if b_actual == b_charged else b_charged - b_actual)
    return

if __name__ == '__main__':
    nk = input().rstrip().split()

    n = int(nk[0])

    k = int(nk[1])

    bill = list(map(int, input().rstrip().split()))

    b = int(input().strip())

    bonAppetit(bill, k, b)
