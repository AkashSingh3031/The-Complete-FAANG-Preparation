# 1st Solution------------------------------------------
n = int(input())
X = list(map(float, input().strip().split()))
Y = list(map(float, input().strip().split()))

mx = sum(X) / n
my = sum(Y) / n

stdv_x = (sum([(i - mx)**2 for i in X]) / n)**0.5
stdv_y = (sum([(i - my)**2 for i in Y]) / n)**0.5

covariance = sum([(X[i] - mx) * (Y[i] -my) for i in range(n)])

correlation_coefficient = covariance / (n * stdv_x * stdv_y)

print(round(correlation_coefficient, 3))

# 2nd Solution----------------------------------------
def get_rank(X, n):
    x_rank = dict((x, i+1) for i, x in enumerate(sorted(set(X))))
    return [x_rank[x] for x in X]
    
n = int(input())
X = list(map(float, input().split()))
Y = list(map(float, input().split()))

rx = get_rank(X, n)
ry = get_rank(Y, n)

d = [(rx[i] -ry[i])**2 for i in range(n)]
rxy = 1 - (6 * sum(d)) / (n * (n*n - 1))

print('%.3f' % rxy)
