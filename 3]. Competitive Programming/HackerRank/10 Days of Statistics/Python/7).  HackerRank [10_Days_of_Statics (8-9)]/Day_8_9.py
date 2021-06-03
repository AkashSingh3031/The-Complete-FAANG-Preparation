### Day-8

# 1st Solution-----------------------------------
n = 5
xy = [map(int, input().split()) for _ in range(n)]
sx, sy, sx2, sxy = map(sum, zip(*[(x, y, x**2, x*y) for x, y in xy]))
b = (n*sxy - sx*sy)/(n*sx2 - sx**2)
a = (sy/n) - b*(sx/n)
print('{:.3f}'.format(a+b*80))

# 2nd Solution--------------------

# "QUESTION"-------->
'''
The regression line of y on x is 3x+4y+8=0, and the regression line of x on y is 4x+3y+7=0. What is the value of the Pearson correlation coefficient?

##Note: If you haven't seen it already, you may find our "Pearson Correlation Coefficient Tutorial" helpful in answering this question.
'''
# "ANSWES"------>

#    1
#   -1
#  3/4
# -4/3
#  4/3

###  -3/4 (CURRECT)






#==============================================================

### Day-9
import numpy as np
m,n = [int(i) for i in input().strip().split(' ')]
X = []
Y = []

for i in range(n):
    data = input().strip().split(' ')
    X.append(data[:m])
    Y.append(data[m:])

q = int(input().strip())
X_new = []

for x in range(q):
    X_new.append(input().strip().split(' '))
X = np.array(X,float)
Y = np.array(Y,float)
X_new = np.array(X_new,float)

X_R = X-np.mean(X,axis=0)
Y_R = Y-np.mean(Y)

beta = np.dot(np.linalg.inv(np.dot(X_R.T,X_R)),np.dot(X_R.T,Y_R))

X_new_R = X_new-np.mean(X,axis=0)
Y_new_R = np.dot(X_new_R,beta)
Y_new = Y_new_R + np.mean(Y)

for i in Y_new:
    print(round(float(i),2))
