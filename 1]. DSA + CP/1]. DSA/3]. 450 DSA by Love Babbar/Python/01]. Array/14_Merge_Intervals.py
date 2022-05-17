"""
Question link : https://leetcode.com/problems/merge-intervals/
"""

"""
-----------------------------EXPLANATION-----------------------------------
The main problem in solving this question is that intervals are randomly distributed in an array
it means that if we took one intervals then there are lot of possibility :- may be it is merging with 
the last interval, maybe mid interval and maybe it is not merging at all

For example : Let arr = [[1, 3], [20, 30], [2, 6], [15, 35], [4, 6]]

The first interval [1, 3] is merging with 3rd [2, 6] and last interval [4, 6]
Now how we (a human) know that the first interval is merging with the 3rd and last interval. The answer
is simple we scan the whole array and find all the intervals which are merging with the first interval.
Now computer can also use this approach to find the solution. But the time complexity of that approach will
be O(n^2) because we are scanning the whole array for a each interval. But we want more efficient solution

So how can we solve this:
If some how array are arranged in such a way that each merging intervals are next to each other then we
know where to look for a particular interval

For example : [[1, 3], [2, 6], [4, 6], [15, 35], [20, 30]]   (we sort the array)

Now if we took interval [1, 3] and compare it with [2, 6] we can easily say that it is merging.
After merging it the interval became [1, 6] now we compare it with [4, 6] and again it merging and so on

So how just by arranging an array this question became less difficult to solve.

"""

"""
-------------------------------------------APPROACH---------------------
-We sort the given array
-We create new array for storing updated intervals. Initial value of this array will be the first element of arr
-Now we began the loop from arr[1:] because we already stored the 1st interval in updated array and since
the array is sorted we know it's the right interval
-Now we compare the current interval from the arr to the store interval in updated interval to see if they are merging
or not.
-Now there are 2 type of merging. Either we merge the interval to form the new interval or drop the interval
entirely
For example : [1, 4] and [2, 6]. Here 2 < 3 then there will definitely be a merging and since 4 < 6 therefore
we update the arr with interval [1, 6]. But if we are given [1, 4] and [2, 3] since 2 < 4 but 4 > 3 therefore
we have to drop the [2, 3] and the array will remain the same
-That's what we need to check in the if statement
-But if there is no merging we simply add that interval to the updated interval
-At last we return the updated_interval
"""


# -----------------------------------------ALGORITHM------------------------------------------
def merge(arr):
    """
    Time Complexity : O(nlogn)
    Auxiliary Space Complexity : O(n)
    """
    arr.sort()
    updated_interval = [arr[0]]  # Created new array to store all the merged interval
    current_index = 0
    for intervals in arr[1:]:
        # For merging
        if intervals[0] <= updated_interval[current_index][1] < intervals[1]:
            updated_interval[current_index] = [updated_interval[current_index][0], intervals[1]]
        # If they are not merging
        elif updated_interval[current_index][1] < intervals[0]:
            updated_interval.append(intervals)
            current_index += 1

    return updated_interval


print(merge([[1, 4], [4, 5], [6, 10], [5, 11]]))
