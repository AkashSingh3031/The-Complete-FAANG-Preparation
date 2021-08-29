"""
Function to Reverse an Array

Takes in an Array and Returns an New Array
"""


def reverse(arr):
    new_arr = []

    for index in range(len(arr)):
        new_arr.insert(0, arr[index])

    return new_arr


arr = [1, 2, 3, 4, 5]
new_arr = reverse(arr)

print("Before Reverse:", arr)
print("After Reverse:", new_arr)
