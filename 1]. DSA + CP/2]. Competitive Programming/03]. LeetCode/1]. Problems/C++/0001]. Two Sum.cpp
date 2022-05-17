/*
Example 1:
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
  Input: nums = [3,2,4], target = 6
  Output: [1,2]

Example 3:
  Input: nums = [3,3], target = 6
  Output: [0,1]
*/

class Solution
{
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++)
        {
            if(hash.find(target-nums[i]) != hash.end())
                return {hash[target-nums[i]], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};
