# 10th Solutions
#--------------------------

factorial = lambda x: 1 if x <= 1 else x*factorial(x-1)
print(factorial(int(input())))
