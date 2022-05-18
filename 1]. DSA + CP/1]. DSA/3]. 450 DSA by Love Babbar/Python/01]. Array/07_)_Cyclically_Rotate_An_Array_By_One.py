# Question link https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

"""
INPUT : [1, 2, 3, 4, 5]
OUTPUT : [5, 1, 2, 3, 4]
Just rotate the array by one
"""


def rotate(arr):
    """
    Time Complexity : O(n)
    Space Complexity : O(1)
    """
    return arr.insert(0, arr.pop())


arr = [1, 2, 3, 4, 5]
rotate(arr)
print(arr)
