# Program to sort 0,1,2 without using any sorting algorithm
"""
EXAMPLE :
INPUT : [0,2,2,1,0]
OUTPUT : [0,0,1,2,2]
"""

# I am using DNF(Dutch National Flag) algorithm
# You can read about it here : https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/

def sort012(arr):
    """
    Time Complexity : O(n) (But only one traversals is required)
    Space Complexity : O(1)
    """
    low, mid, high = 0, 0, len(arr) - 1
    while mid <= high:
        if arr[mid] == 0:
            arr[mid], arr[low] = arr[low], arr[mid]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1
    return arr


print(sort012([0, 2, 1, 2, 0]))
