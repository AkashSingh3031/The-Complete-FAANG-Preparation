/*
Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]
*/ 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        return kSum(nums, target, 0, 4); 
    }
    
    vector<vector<int>> kSum(vector<int> &nums,int target, int start, int k){
        vector<vector<int>> res;
        
        if(start == nums.size()){
            return res;
        }
        
        int average_value = target / k;
        
        if(nums[start] > average_value || nums.back() < average_value){
            return res;
        }
        
        if(k == 2)
            return twoSum(nums, target, start);
        
        for(int i=start; i<nums.size(); i++){
            if(i == start || nums[i] != nums[i-1]){
                for(vector<int> &subset : kSum(nums, static_cast<long>(target)-nums[i], i+1, k-1)){
                    subset.insert(subset.begin(), nums[i]);
                    res.push_back(subset);
                }
            }
        }
        
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int> &nums, int target,int start){
        vector<vector<int>> res;
        int low, high, curr_sum;
        
        low = start; high = nums.size()-1;
        
        while(low < high){
            curr_sum = nums[low] + nums[high];
            
            if(curr_sum < target || (low > start && nums[low] == nums[low-1])){
                low++;
            }
            else if(curr_sum > target || (high < nums.size()-1 && nums[high] == nums[high+1])){
                high--;  
            }
            else{
                res.push_back({nums[low], nums[high]});
                low++;
                high--;
            }
        }
        return res;
    }
};