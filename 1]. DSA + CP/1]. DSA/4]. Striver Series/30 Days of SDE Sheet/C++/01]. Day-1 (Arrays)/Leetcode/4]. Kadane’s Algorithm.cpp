class Solution 
{
  public:
    int maxSubArray(vector<int>& nums)
    {
        int curr_sum = nums[0], max_sum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            curr_sum = max(nums[i], curr_sum+nums[i]);
            if(curr_sum > max_sum)
                max_sum = curr_sum;
        }
        return max_sum;
    }
};
