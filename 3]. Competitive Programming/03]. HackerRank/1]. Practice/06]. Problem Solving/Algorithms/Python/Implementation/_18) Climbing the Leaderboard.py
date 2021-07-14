
# Contributed by Paraj Shah
# https://github.com/parajshah

n = int(input())
ranked = list(map(int, input().split()))
m = int(input())
player = list(map(int, input().split()))

leaderboard = sorted(set(ranked), reverse = True)
l = len(leaderboard)

for a in player:
    while (l > 0) and (a >= leaderboard[l - 1]):
        l -= 1
    print(l + 1)
