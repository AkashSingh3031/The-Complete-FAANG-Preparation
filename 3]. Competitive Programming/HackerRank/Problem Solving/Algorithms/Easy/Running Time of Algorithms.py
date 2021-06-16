
# Contributed by Paraj Shah
# https://github.com/parajshah

def runningTime(arr):
    count = 0
    for i in range(1, len(arr)):
        element = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > element:
            arr[j + 1] = arr[j]
            j -= 1
            count += 1
        arr[j + 1] = element
    return count