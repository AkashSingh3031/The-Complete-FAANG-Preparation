
# Contributed by Paraj Shah
# https://github.com/parajshah

def quickSort(arr):
    p = arr[0]

    left = [arr[i] for i in range(len(arr)) if arr[i] < p]
    equal = [arr[i] for i in range(len(arr)) if arr[i] == p]
    right = [arr[i] for i in range(len(arr)) if arr[i] > p]

    answer = left + equal + right
    return answer