class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int m=1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[m-1]){
                nums[m] = nums[i];
                m++;
            }
        }
        return m;
    }
};