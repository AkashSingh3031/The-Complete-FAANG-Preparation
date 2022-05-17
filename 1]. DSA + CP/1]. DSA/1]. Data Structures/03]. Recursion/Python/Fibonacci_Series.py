# To print the fibonacci series
#0 1 1 2 3 5 8

def fib(n):
    if n==0 or n==1:
        return n
    else:
        return fib(n-2)+fib(n-1)
for i in range(6):
    print(fib(i), end = " ")
