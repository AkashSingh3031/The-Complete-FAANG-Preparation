/*
'''
209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.
'''
*/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = (int)nums.size();
        int sum = 0, j = 0;
        int res = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                res = min(res, i - j + 1);
                sum -= nums[j++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

//
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size(),
            len = INT_MAX;
        vector<int> sums(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = n; i >= 0 && sums[i] >= s; i--)
        {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};