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

