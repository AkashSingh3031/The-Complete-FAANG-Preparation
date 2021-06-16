
# Contributed by Paraj Shah
# https://github.com/parajshah

def insertionSort1(n, arr):
    lastElement = arr[-1]
    
    for i in range(len(arr) - 1, -1, -1):
        if arr[i - 1] >= lastElement and i != 0:
            arr[i] = arr[i - 1]
            print(*arr)
        else:
            arr[i] = lastElement
            print(*arr)
            return