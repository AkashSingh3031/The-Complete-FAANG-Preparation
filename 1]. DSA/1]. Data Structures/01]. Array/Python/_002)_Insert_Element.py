"""
Function to insert element at a given position

Takes an Array an position and an element as arguments
"""


def insert(arr, position, element):

    next_element = element

    for index in range(position, len(arr)):
        current = arr[index]
        arr[index] = next_element
        next_element = current

    arr.append(next_element)


arr = [1, 2, 3, 5]
print("Array before insertion:", arr)

insert(arr, 1, -4)
print("After insertion:", arr)
