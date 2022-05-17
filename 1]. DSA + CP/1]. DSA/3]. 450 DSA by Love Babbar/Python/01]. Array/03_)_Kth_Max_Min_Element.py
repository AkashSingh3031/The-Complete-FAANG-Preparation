# Question link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#

def kth_min_element(arr, k):
    """
    Time complexity : O(nlogn)
    Space Complexity : O(1)
    """
    arr.sort()
    return arr[k - 1]


print(kth_min_element([1, 2, 3, 4, 5], 3))
