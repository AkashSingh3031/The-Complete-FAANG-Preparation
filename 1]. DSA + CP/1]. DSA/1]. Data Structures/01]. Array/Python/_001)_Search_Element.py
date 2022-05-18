# function to perform linear search for element in array
def search(arr, element):
    for index in range(0, len(arr)):
        if arr[index] == element:
            return index

    # if no such number exist in the array return -1
    return -1


arr = [20, 5, 7, 25]
element = 5

print("Array Searched:", arr)
print("Searching for:", element)
print("Searched index=", search(arr, element))
