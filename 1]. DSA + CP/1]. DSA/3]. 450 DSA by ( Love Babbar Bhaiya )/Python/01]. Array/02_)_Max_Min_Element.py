# Algorithm that find maximum and minimum number in given array in minimum number of comparison

def minimum_number_of_comparison(arr, length):
    """
    TIME COMPLEXITY : O(n)
    if n is odd : number of comparison is 3(n - 1) / 2
    if n is even : number of comparison is 3(n - 2) / 2 + 1
    """

    # if length is odd
    if length % 2 == 0:
        maximum_number = max(arr[0], arr[1])
        minimum_number = min(arr[0], arr[1])
        i = 2

    # if length is even
    else:
        maximum_number = minimum_number = arr[0]
        i = 1

    while i < length - 1:
        if arr[i] < arr[i + 1]:
            maximum_number = max(maximum_number, arr[i + 1])
            minimum_number = min(minimum_number, arr[i])
        else:
            maximum_number = max(maximum_number, arr[i])
            minimum_number = min(minimum_number, arr[i + 1])
        i += 2

    return maximum_number, minimum_number


arr = [1, 2, 3, 4]

maximum, minimum = minimum_number_of_comparison(arr, len(arr))
print(f'Maximum number among {arr} is {maximum}')
print(f'Minimum number among {arr} is {minimum}')
