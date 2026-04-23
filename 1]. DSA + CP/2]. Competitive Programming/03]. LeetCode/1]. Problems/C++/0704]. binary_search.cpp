/*
704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int index = -1, i;
        for (i = 0; i < len; i++)
        {
            if (nums[i] == target)
            {
                index = i;
                break;
            }
        }
        // cout<<target<<" exists at in  nums and its index is "<<index;
        return index;
    }
};

//time
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        int n = (int)nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};