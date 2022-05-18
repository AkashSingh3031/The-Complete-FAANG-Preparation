# Find the contiguous sub-array(containing at least one number) which has the maximum sum
"""
EXAMPLE:
    INPUT : [1, 2, 3, -2, 5]
    OUTPUT : 9
    EXPLANATION :
    Because sub-array (1,2,3,-2,5) has maximum sum among all sub-array.
    For example : sub-array (1,2,3) has sum 6
                  sub-array (1,2,3,-2) has sum 4
                  sub-array (3,-2,5) has sum 6
                  and so on..................
                  Final max sum will be 9 and hence we return it
"""

"""
------------------------------IMPORTANT NOTE---------------------------------

This algorithm update the given array so if you are restricted to update the
given array see _08_i_)_Kadane's_Algorithm
"""

"""
------------------------------EXPLANATION----------------------------------------

The main idea in this algorithm is: 
Each time we took 2 element (array[n] and array[n + 1]) from the given array and add them
If there summation is greater than array[n + 1] then we replace the value of array[n + 1]
with the summation.

After we finishes with updating the array we simply return the maximum among the
array

For example:
arr = [-2, 2, 3, -2]
Now the loop began:

--------------1st iteration--------------------
summation = arr[0] + arr[1] = 0
is summation > arr[1] 
no so we continue without replacing 

--------------2nd iteration--------------------
summation = arr[1] + arr[2] = 5
is summation > arr[2]
yes so we replace arr[2] with summation
updated arr = [-2, 2, 5, -2]

--------------3nd iteration--------------------
summation = arr[2] + arr[3] = 3
is summation > arr[3]
yes so we replace arr[3] with summation
updated arr = [-2, 2, 5, 3]

loop ends

we return max among the updated array 
which is 5
"""


def max_sub_array(arr):
    """
    TIME COMPLEXITY : O(n)
    SPACE COMPLEXITY : O(1)
    """
    for i in range(len(arr) - 1):
        summation = arr[i] + arr[i + 1]
        arr[i + 1] = max(summation, arr[i + 1])
    return max(arr)


print(max_sub_array([-2, 2, 3, -2]))
