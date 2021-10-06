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


array = [x for x in range(1, 11)]
print("Input array:", array)

verify(binary_search(array, 6), 6)
verify(binary_search(array, 20), 20)
