#finding gcd of 2 numbers recursively
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b, a%b)

a = 10
b = 4
if a>b:
    a,b = b,a
print(gcd(a,b))