"""
Function to rotate an the first element
"""


def left_rotate(arr, num):
    tmp = arr[0]

    for index in range(1, num):
        arr[index - 1] = arr[index]

    arr[num - 1] = tmp


arr = [1, 2, 3, 4, 5]
num = 2

print("Before Left Rotation:", arr)

left_rotate(arr, num)
print("After '1' Left Rotation:", arr)
