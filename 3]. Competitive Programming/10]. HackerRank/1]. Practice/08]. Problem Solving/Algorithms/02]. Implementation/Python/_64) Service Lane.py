
# Contributed by Paraj Shah
# https://github.com/parajshah

def serviceLane(width, i, j):
    return min(width[i : j + 1])

n, t = map(int, input().split())
width = list(map(int, input().split()))
for _ in range(t):
    i, j = map(int, input().split())
    print(serviceLane(width, i, j))