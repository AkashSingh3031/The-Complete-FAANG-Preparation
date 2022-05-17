# Question link https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

"""
------------------------------EXPLANATION-----------------------------------------
When you begin to solve this question the main problem you may face that you don't know in which
height you should add or subtract k to minimise the difference. Now what I mean by that let's take an example:

let arr = [1, 5, 8, 10] and k = 2(number to subtract or add)
Now to minimise the difference between largest and smallest height after adding or subtracting k, you may
thought that if I add the k in the smallest height and subtract k from the largest height I will definitely be
able to minimise the difference. In this example your thought process is correct.
After subtracting and adding k in highest and lowest height there are 4 possible array we get among them
[3, 3, 6, 8]
[3, 7, 6, 8]
these are the only array which give us the minimum difference

Your thought process is correct but it's incomplete. For example
let arr = [5, 2, 1, 10] and k = 3
Now if you try to minimise the height by subtracting and adding k to highest and lowest height you get
3 ((10 - 3) - (1 + 3)) but that's wrong answer the correct answer is 4. Now how that's

You have to add or subtract k from all number in the given array and not just the highest and lowest, and
that will cause the problem in your approach because there may be some height in which if you add k then
they will became maximum and same goes for smallest height.
And in the above example it's the 5 that's causing the problem. If you add 3 in 5 it became maximum
and if you subtract 3 it became minimum.

So when you scan the array you have to keep track of which is highest and which is lowest height right now
so that you can add k in lowest and subtract k from the highest. Sorting is the best way to tackle this
type of problem where you have to keep track of highest and lowest. Because if you are at some index i in
array then you definitely know that arr[i] <= arr[i + 1]

----------------------------------Approach-----------------------------------------
So now the problem became simple with these steps:
- You sort the array
- You assign some max value to current_difference (To keep track of difference between heights)
- You assign small and large height according to 1st approach discuss above
(This point is very important notice how second example causing problem because there is existing some
number which can became maximum and minimum if we add subtract or add k in it. But if now such element exist
then it's your first and last number that gives minimum difference)
- Now loop start
- Compare that if on subtracting k from current largest height is it became less than the current smallest height
- Compare that if on add k to current lowest height is it became grater than the current highest height
- Height can't be negative so we discard the case where small became negative
- At last we store the minimum difference upto now

"""


def minimise_the_height(arr, k):
    """
    Time Complexity : O(nlogn)
    Auxiliary Space Complexity : O(1)
    """
    arr.sort()
    current_diff = arr[-1] - arr[0]
    small = arr[0] + k
    large = arr[-1] - k
    for i in range(len(arr) - 1):
        minimum = min(small, arr[i + 1] - k)
        maximum = max(large, arr[i] + k)
        if minimum < 0:
            continue
        current_diff = min(current_diff, maximum - minimum)
    return current_diff


print(minimise_the_height([5, 1, 2, 10], 3))
