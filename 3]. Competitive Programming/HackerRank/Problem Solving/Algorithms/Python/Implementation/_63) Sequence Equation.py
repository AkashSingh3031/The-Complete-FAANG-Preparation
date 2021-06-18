
# Contributed by Paraj Shah
# https://github.com/parajshah

n = int(input().strip())
p = list(map(int,input().strip().split(' ')))
for i in range(n):   
    print(p.index(p.index(i+1)+1)+1)
