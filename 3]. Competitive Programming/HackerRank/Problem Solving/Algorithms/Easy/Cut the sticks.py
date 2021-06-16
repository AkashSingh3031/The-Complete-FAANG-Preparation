
# Contributed by Paraj Shah
# https://github.com/parajshah

from collections import deque

def cutTheSticks(arr):
    ls = []
    while len(arr) >= 1:
        ls.append(len(arr))
        minimum = min(arr)
        arr = [i - minimum for i in arr if i != minimum]
    return ls