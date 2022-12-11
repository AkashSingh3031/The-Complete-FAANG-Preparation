# 1st Solution------------------------------------
def fact(n):
    return 1 if n == 0 else n*fact(n-1)

def comb(n, x):
    return fact(n) / (fact(x) * fact(n-x))

def eq(x, n, p):
    return comb(n, x) * p**x * (1-p)**(n-x)

l, r = list(map(float, input().split(" ")))
odds = l / r
print(round(sum([eq(i, 6, odds / (1 + odds)) for i in range(3, 7)]), 3))


# 2nd Solution-------------------------------------
def fact(n):
    return 1 if n == 0 else n*fact(n-1)

def comb(n, x):
    return fact(n) / (fact(x) * fact(n-x))

def eq(x, n, p):
    return comb(n, x) * p**x * (1-p)**(n-x)

p, n = list(map(int, input().split(" ")))
print(round(sum([eq(i, n, p/100) for i in range(3)]), 3))
print(round(sum([eq(i, n, p/100) for i in range(2, n+1)]), 3))


# 3rd Solution------------------------------------
def geometric_distributon(n,p):
    return ((1-p)**(n-1))*p

a, b = list(map(int, input().split()))
n = int(input())
print('{:.3f}'.format(geometric_distributon(n, a/b)))


# 4th Solution------------------------------------------
print(round(sum([(1 - (1 / 3))**(5 - x) * (1 / 3) for x in range(1, 6)]), 3))
