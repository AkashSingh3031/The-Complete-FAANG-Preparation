# Question link https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

def union(arr1, arr2):
    """
    Time Complexity : O(n)
    Space Complexity : O(n)
    """
    return len(set(arr1 + arr2))


print(union([1, 2, 3, 4, 5], [1, 2, 3]))
