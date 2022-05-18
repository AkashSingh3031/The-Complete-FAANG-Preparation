"""
Detailed Explanation at : https://www.geeksforgeeks.org/jump-search/
"""

from math import floor, sqrt


def jump_search(array, target):
    # Best step value = root(n)
    step = floor(sqrt(array_len := len(array)))

    step_start = 0
    step_end = step

    while step_start < array_len:
        if step_end > array_len:
            step_end = array_len

        if step_end > target:
            for index in range(step_start, step_end):
                if array[index] == target:
                    return index
        else:
            step_start = step_end
            step_end += step

    return None


def verify(index, target):
    if index is not None:
        print("Target", target, "found at index:", index)
    else:
        print("Target", target, "not in list")


array = [x for x in range(1, 51)]
print("Input array:", array)

verify(jump_search(array, 30), 30)
verify(jump_search(array, 70), 70)
