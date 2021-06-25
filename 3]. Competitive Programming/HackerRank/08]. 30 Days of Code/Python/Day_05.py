##### 6th solution
#---------------------------------------------------------
#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(input())
    print(*['%d x %d = %d' % (n, i, n*i) for i in range(1, 11)], sep='\n')