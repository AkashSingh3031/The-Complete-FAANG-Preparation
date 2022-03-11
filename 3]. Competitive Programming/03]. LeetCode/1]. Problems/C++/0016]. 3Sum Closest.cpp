/*
Example 1:
    Input: nums = [-1,2,1,-4], target = 1
    Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
    Input: nums = [0,0,0], target = 1
    Output: 0
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n-2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (abs(ans - target) > abs(sum3 - target))
                    ans = sum3;
                if (sum3 == target) 
                    break;
                if (sum3 > target)
                    --r; 
                else
                    ++l;
            }
        }
        return ans;
    }
};