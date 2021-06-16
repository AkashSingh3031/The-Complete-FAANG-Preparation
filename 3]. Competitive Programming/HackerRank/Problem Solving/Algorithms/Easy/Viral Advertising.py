
# Contributed by Paraj Shah
# https://github.com/parajshah

import math

def viralAdvertising(n):
    shares = 5
    likes = math.floor(shares / 2)
    total = likes
    for _ in range(n - 1):
        shares = likes * 3
        likes = math.floor(shares / 2)
        total += likes
    return total