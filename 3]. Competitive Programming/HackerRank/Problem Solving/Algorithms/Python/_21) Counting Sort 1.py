
# Contributed by Paraj Shah
# https://github.com/parajshah

def countingSort(arr):
    counts = [0] * 100
    for i in arr:
        counts[i] += 1
    return counts