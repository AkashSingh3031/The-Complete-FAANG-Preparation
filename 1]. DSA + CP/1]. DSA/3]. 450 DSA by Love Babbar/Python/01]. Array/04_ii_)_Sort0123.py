# It simply based on counting 0s 1s 2s and then updating the given array
def sort012_method2(arr):
    """
    Time Complexity : O(n) (Two traversals is required) (One traversal approach is discussed in 04_ii_)_Sort012.py)
    Space Complexity : O(1)
    """
    zero, one, two = 0, 0, 0

    # Counting
    # This loop TIME COMPLEXITY is : O(n)
    for number in arr:
        if number == 0:
            zero += 1
        elif number == 1:
            one += 1
        else:
            two += 1

    # Recreating array with new value
    # Remember I am not using any extra space I am just updating the existing array
    # This loop TIME COMPLEXITY is : O(n)
    i = 0
    while zero > 0:
        arr[i] = 0
        i += 1
        zero -= 1
    while one > 0:
        arr[i] = 1
        i += 1
        one -= 1
    while two > 0:
        arr[i] = 2
        i += 1
        two -= 1
    return arr


print(sort012_method2([0, 2, 1, 2, 0]))