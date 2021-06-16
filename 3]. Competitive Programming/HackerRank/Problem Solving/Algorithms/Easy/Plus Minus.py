
# Contributed by Paraj Shah
# https://github.com/parajshah

def plusMinus(arr):
    countPositive = 0
    countNegative = 0
    countZero = 0
    l = len(arr)
    for i in range(l):
        if arr[i] > 0:
            countPositive += 1
        if arr[i] < 0:
            countNegative += 1
        if arr[i] == 0:
            countZero += 1
    
    print(countPositive / l)
    print(countNegative / l)
    print(countZero / l)
    return