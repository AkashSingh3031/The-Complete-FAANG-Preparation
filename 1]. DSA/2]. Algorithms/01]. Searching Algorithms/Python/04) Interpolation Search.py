"""
# Explanation: 
    - https://kartikkukreja.wordpress.com/2013/08/17/beating-binary-search-the-interpolation-search/
    - https://www.geeksforgeeks.org/interpolation-search/
"""


def interpolation_search(array, target):
    lo = 0
    hi = len(array) - 1

    while hi >= lo and target >= array[lo] and target <= array[hi]:
        # Equation to find position:
        pos = lo + (target - array[lo]) * (hi - lo) / (array[hi] - array[lo])
        pos = int(pos)

        if array[pos] == target:
            return pos
        elif array[pos + 1] < target:
            lo = pos
        elif array[pos + 1] > target:
            hi = pos

    return None


def verify(index, target):
    if index is not None:
        print("Target", target, "found at index:", index)
    else:
        print("Target", target, "not in list")


array = [x for x in range(1, 51)]
print("Input array:", array)

verify(interpolation_search(array, 30), 30)
verify(interpolation_search(array, 70), 70)
