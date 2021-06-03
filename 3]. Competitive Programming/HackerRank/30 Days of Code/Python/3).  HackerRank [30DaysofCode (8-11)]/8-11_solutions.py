##### 9th Solutions
#--------------------------
n = int(input())
d = {}

for i in range(n):
    x = input().split()
    d[x[0]] = x[1]

while True:
    try:
        name = input()
        if name in d:
            print(name, '=', d[name], sep='')
        else:
            print('Not found')
    except:
        break


##### 10th Solutions
#--------------------------
factorial = lambda x: 1 if x <= 1 else x*factorial(x-1)
print(factorial(int(input())))


##### 11th Solutions
#--------------------------
n = int(input().strip())

numbers = str(bin(n)[2:]).split('0')
lengths = [len(num) for num in numbers]

print(max(lengths))



##### 12th Solutions
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


