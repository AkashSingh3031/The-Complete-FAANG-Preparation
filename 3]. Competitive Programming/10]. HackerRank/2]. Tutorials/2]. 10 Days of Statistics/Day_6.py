# 1st Solution------------------------------------------------
import math as m

x, n, m, s = int(input()),int(input()), int(input()),int(input())
m1 = n*m
s1 = m.sqrt(n)*s

def cdf(x, m, s):
    z = (x-m)/s
    return 0.5*(1 + m.erf(z/(m.sqrt(2))))

print(round(cdf(x, m1, s1), 4))


# 2nd Solution-------------------------------------------
import math

x, n = 250, 100
s_mean, s_stdev = 2.4, 2.0

stdev = s_stdev * math.sqrt(n)

cdf = 0.5*(1+math.erf((x-s_mean*n)/(stdev * math.sqrt(2))))

print(round(cdf, 4))


# 3rd Solution-----------------------------------------------
from math import sqrt 

a, b, c, d, e = int(input()), int(input()), int(input()), float(input()), float(input())

print(round(b - (c/sqrt(a))*e, 2))
print(round(b + (c/sqrt(a))*e, 2))
