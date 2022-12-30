class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goodIndx = n-1;
        for(int i=n-2;i>=0;i--){
            
            if(i+nums[i]>=goodIndx){
                goodIndx = i;
            }
            
        }
        
        if(goodIndx == 0){
            return true;
        }else{
            return false;
        }
    }
};
