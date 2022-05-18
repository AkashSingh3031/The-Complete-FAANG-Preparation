#optimized method using reverse function
def reverse(lst, l, r):
    while(l<r):
        lst[l], lst[r] = lst[r], lst[l]
        l+=1
        r-=1

def optimized(l,d):
    n = len(l)
    reverse(l,0,n-1)
    reverse(l,0,d-1)
    reverse(l,d,n-1)

l = [10,20,30,40,50]
d = 3
optimized(l,d)
print(l)