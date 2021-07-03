class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        int i = nums.size()-2,j = i+1;
        while(i >= 0 && nums[i] >= nums[i+1] ) i--;
        if(i >= 0){
            while(i>= 0 && nums[i] >= nums[j]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};