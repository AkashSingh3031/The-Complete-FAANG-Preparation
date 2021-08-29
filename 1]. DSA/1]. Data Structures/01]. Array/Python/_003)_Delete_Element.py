"""
Function to delete an element in an array

Takes in an array and an element to delete

Returns an new Array
"""


def delete(arr, element):
    if element not in arr:
        return "no such element exist in array"

    new_arr = []

    for index in range(len(arr)):
        if arr[index] != element:
            new_arr.append(arr[index])

    return new_arr


arr = [1, 2, 3, 5]
element = 2

print("Before deletion:", arr)
print("Deleting:", element)

new_arr = delete(arr, element)
print("After deletion:", new_arr)
