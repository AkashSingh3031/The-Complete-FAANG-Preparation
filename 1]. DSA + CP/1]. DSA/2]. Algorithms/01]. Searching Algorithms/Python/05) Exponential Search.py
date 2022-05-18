"""
# Explanation:
    - https://www.geeksforgeeks.org/exponential-search/
"""


def exponential_search(array, target):
    if array[0] == target:
        return 0

    index = 1

    while index < len(array) and target < array[-1]:

        if array[index] == target:
            return index

        elif array[index] < target:
            index *= 2

        elif array[index] > target:
            index_in_subarray = binary_search(array[(index // 2) : index], target)
            return index_in_subarray + index // 2

    return None


def binary_search(array, target):
    first = 0
    last = len(array) - 1

    while first <= last:
        midpoint = (first + last) // 2

        if array[midpoint] == target:
            return midpoint

        elif array[midpoint] < target:
            first = midpoint + 1

        elif array[midpoint] > target:
            last = midpoint - 1

    return None


def verify(index, target):
    if index is not None:
        print("Target", target, "found at index:", index)
    else:
        print("Target", target, "not in list")


array = [x for x in range(1, 51)]
print("Input array:", array)

verify(exponential_search(array, 30), 30)
verify(exponential_search(array, 70), 70)
