"""
Detailed Explanation at : https://www.geeksforgeeks.org/fibonacci-search/

Runtime: O(log(n))
"""


def fibonacci_search(array, target):
    fibm2 = 0
    fibm1 = 1
    fib = fibm1 + fibm2

    while fib < len(array):
        fibm2 = fibm1
        fibm1 = fib
        fib = fibm1 + fibm2

    offset = -1

    while fib > 1:
        # Check if fibMm2 is a valid location
        i = min(offset + fibm2, len(array) - 1)

        if array[i] < target:
            fib = fibm1
            fibm1 = fibm2
            fibm2 = fib - fibm1
            offset = i

        elif array[i] > target:
            fib = fibm2
            fibm1 = fibm1 - fibm2
            fibm2 = fib - fibm1

        else:
            # element found !
            return i

    # comparing the last element with target
    if fibm1 and len(array) - 1 == target:
        return len(array) - 1

    # element not found
    return None


def verify(index, target):
    if index is not None:
        print("Target", target, "found at index:", index)
    else:
        print("Target", target, "not in list")


array = [x for x in range(1, 51)]
print("Input array:", array)

verify(fibonacci_search(array, 30), 30)
verify(fibonacci_search(array, 70), 70)
