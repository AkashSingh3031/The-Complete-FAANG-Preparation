# Program to sort 0,1,2 without using any sorting algorithm
"""
EXAMPLE :
INPUT : [0,2,2,1,0]
OUTPUT : [0,0,1,2,2]
"""


# I have solved this problem with 2 approach

# METHOD 1
# In method 1 I am using DNF(Dutch National Flag) algorithm
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


# METHOD 2
# It simply based on counting 0s 1s 2s and then updating the given array
def sort012_method2(arr):
    """
    Time Complexity : O(n) (Two traversals is required)
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
