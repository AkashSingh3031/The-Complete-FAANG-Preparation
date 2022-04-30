# 1st Solution---------------------------------------
from math import factorial, exp

f = float(input())
i = int(input())

eq = ((f**i) * exp(-f))/factorial(i)
print('%.3f' %eq)


# 2nd Solution-------------------------------------------
x,y = [float(i) for i in input().split(" ")]

cx = 160 + 40*(x + x**2)
cy = 128 + 40*(y + y**2)

print(round(cx, 3))
print(round(cy, 3))


# 3rd Solution---------------------------------------------
import math as m
mean, std = 20, 2

cd = lambda x: 0.5 * (1 + m.erf((x-mean) / (std * (2**0.5))))

print('{:.3f}'.format(cd(19.5)))
print('{:.3f}'.format(cd(22)-cd(20)))



# 4th Solution--------------------------------------------
import math as m
mean, std = 70, 10
cd = lambda x: 0.5 * (1 + m.erf((x - mean) / (std * (2 ** 0.5))))

print(round((1-cd(80))*100,2))
print(round((1-cd(60))*100,2))
print(round((cd(60))*100,2))
