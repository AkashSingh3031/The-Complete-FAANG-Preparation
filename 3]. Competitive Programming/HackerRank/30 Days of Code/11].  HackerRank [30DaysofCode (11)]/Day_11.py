# 12th Solutions
#--------------------------
#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    current = sum(arr[0][0:3]) + arr[1][1] + sum(arr[2][0:3])
    for i in range(4):
        for j in range(4):
            sumArr = sum(arr[i][j:j+3]) + arr[i+1][j+1] + sum(arr[i+2][j:j+3])
            if sumArr > current:
                current=sumArr 
    print(current)
