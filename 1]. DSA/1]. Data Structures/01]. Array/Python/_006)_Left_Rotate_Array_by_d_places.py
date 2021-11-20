#rotate left by d places
l = [10,20,30,40,50]
d = 3
#ans = [40,50,10,20,30]
#left rotate by 3

# method 2 slicing 
print(l[d:]+l[0:d])

l = [10,20,30,40,50]
d = 3

#method 3
for i in range(d):
    l.append(l.pop(0))
print(l)

l = [10,20,30,40,50]
d = 3

# method4
n = len(l) 
for k in range(d):
    temp = l[0]
    for i in range(n-1):
        l[i] = l[i+1]
    l[n-1] = temp
print(l)

#optimized method
#using 3 reverses               [10,20,30,40,50] d = 3
# reverse upto d places         [30,20,10,40,50]
# reverse remaining n-d places  [30,20,10,50,40]
# reverse complete              [40,50,10,20,30]
# 3 reverses for any value  of d
def reverse(lst, l, r):
    while(l<r):
        lst[l], lst[r] = lst[r], lst[l]
        l+=1
        r-=1

def optimized(l,d):
    n = len(l)
    reverse(l,0,d-1)
    reverse(l,d,n-1)
    reverse(l,0,n-1)

l = [10,20,30,40,50]
d = 3
optimized(l,d)
print(l)
