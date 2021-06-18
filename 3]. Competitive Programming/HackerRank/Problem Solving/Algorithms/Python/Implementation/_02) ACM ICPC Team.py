
# Contributed by Paraj Shah
# https://github.com/parajshah

from itertools import combinations

n,k = map(int,input().split())
teams = [list(map(int, list(input()))) for i in range(n)]
sums = [sum([x[0] or x[1] for x in list(zip(*i))]) for i in combinations(teams,2)]
print(max(sums), sums.count(max(sums)), sep='\n')
