
# Contributed by Paraj Shah
# https://github.com/parajshah

def insertionSort2(n, arr):
    
    for i in range(1, n):
        element = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > element:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = element
        print(*arr)