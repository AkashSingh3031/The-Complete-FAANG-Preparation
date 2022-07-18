class Solution
{
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> seen;
        for(int i=0; i<nums.size(); i++)
        {
            int firstNumber = nums[i], secondNumber = target-firstNumber;  // firstNumber + secondNumber = target
            
            if(seen.find(secondNumber) != seen.end())
                return {seen[secondNumber], i};
            else
                seen[firstNumber] = i;
        }
        return {};
    }
};
