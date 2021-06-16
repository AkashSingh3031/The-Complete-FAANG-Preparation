
# Contributed by Paraj Shah
# https://github.com/parajshah

def howManyGames(p, d, m, s):
    games = 0
    while s >= 0:
        s -= p
        p = max(p - d, m)
        games += 1
    return games - 1