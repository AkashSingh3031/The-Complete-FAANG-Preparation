/*
'''
169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
'''

*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        if (nums[0] == nums[n / 2])
            return nums[0];
        else if (nums[n - 1] == nums[n / 2])
            return nums[n - 1];
        else
            return nums[n / 2];
    }
};

//time
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int score = 0;
        for (auto n : nums)
        {
            if (n == candidate)
            {
                score++;
            }
            else
            {
                score--;
                if (score < 0)
                {
                    candidate = n;
                    score = 1;
                }
            }
        }
        return candidate;
    }
};