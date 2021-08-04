
# Contributed by Paraj Shah
# https://github.com/parajshah

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the dayOfProgrammer function below.
def dayOfProgrammer(year):
    leap = False
    if year < 1918 and year % 4 == 0:
        leap = True
    elif year < 1918 and year % 4 != 0:
        leap = False
    elif year > 1918:
        if year % 4 == 0:
            leap = True
            if year % 400 == 0:
                leap = True
            elif year % 100 == 0:
                leap = False
    else:
        leap = False
    
    if leap == False and year < 1918:
        return "13.09.{}".format(year)
    elif leap == True and year < 1918:
        return "12.09.{}".format(year) 
    elif leap == False and year > 1918:
        return "13.09.{}".format(year)
    elif year == 1918:
        return "26.09.{}".format(year)
    else:
        return "12.09.{}".format(year)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input().strip())

    result = dayOfProgrammer(year)

    fptr.write(result + '\n')

    fptr.close()
