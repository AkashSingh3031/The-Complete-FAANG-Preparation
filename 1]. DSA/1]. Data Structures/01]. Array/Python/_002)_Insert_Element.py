"""
Function to insert a new element at a given position

Takes the position of an array and an element as arguments
"""


def insert(arr, position, element):
    insert = element
    
    for index in range(position):
        moved, arr[index] = arr[index], insert
        insert = moved
    

arr = [1, 2, 3, 5]
print("Array before insertion:", arr)

insert(arr, 1, -4)
print("After insertion:", arr)
