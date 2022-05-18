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
------------------------------IMPORTANT NOTE----------------------------------------

This algorithm gives the result without updating the actual array.
So if constraind is given that you don't have to update the array then this is the algorithm you are looking for
"""

"""
------------------------------EXPLANATION----------------------------------------

The main idea is that we create 2 variable current_max and max_so_far
we keep adding all the array element in current_max if at any point current_max
became grater than max_so_far we change the value of max_so_far to current_max value
Also if at any point current_so far became negative we reassigned it to 0

For example 
arr = [-2, 3, 2, -2]
current_max = 0
max_so_far = -inf   (-infinite)  
Now we loop through arr and keep adding arr value to current_max

-----------1st iteration----------
current_max = -2, maximum_so_far = -inf   (current_max is negative and greater than max_so_far)
Therefore current_max = 0, maximum_so_far = -2

-----------2nd iteration----------
current_max = 3 , maximum_so_far = 2   (current_max is positive and its value is > maximum_so_far)
Therefore maximum_so_far = 3  

-----------3rd iteration----------
current_max = 5, maximum_so_far = 3
Therefore maximum_so_far = 5

-----------4th iteration----------
current_max = 3, maximum_so_far = 5
Since current_max < maximum_so_far therefore maximum_so_far = 5

At last we return maximum_so_far    
"""


# Implementation of above approach

def max_sub_array(arr):
    """
    Time Complexity : O(n)
    Space Complexity : O(1)
    """
    current_max = 0
    maximum_so_far = float('-inf')
    for i in arr:
        current_max += i
        if current_max > maximum_so_far:
            maximum_so_far = current_max
        if current_max < 0:
            current_max = 0

    return maximum_so_far


print(max_sub_array([-2, 3, 2, -2]))
