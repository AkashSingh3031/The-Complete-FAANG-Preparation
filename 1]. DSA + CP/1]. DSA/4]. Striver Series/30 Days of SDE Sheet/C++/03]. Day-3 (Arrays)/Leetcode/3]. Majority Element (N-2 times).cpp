class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(count == 0)
                majority = nums[i];
            if(majority == nums[i]) 
                count++;
            else 
                count--;
        }
        return majority;
    }
};
