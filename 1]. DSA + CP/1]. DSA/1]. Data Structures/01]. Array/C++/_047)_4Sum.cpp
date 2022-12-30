vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
vector<vector<int>> res;
    
    if(nums.empty()) return res;
    
    int n = nums.size();
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            long target2 = long(target) - long(nums[j]) - long(nums[i]);
            int left = j+1;
            int right = n-1;
            
            while(left < right){
                long twoSum = nums[left] + nums[right];
                if(left < right && twoSum < target2){
                    left++;
                }else if(left < right && twoSum > target2){
                    right--;
                }else{
                    vector<int> storeAns(4,0);
                    storeAns[0] = nums[i];
                    storeAns[1] = nums[j];
                    storeAns[2] = nums[left];
                    storeAns[3] = nums[right];
                    res.push_back(storeAns);
                    
                   while(left < right && nums[left] == storeAns[2]) ++left;
                   while(left < right && nums[right] == storeAns[3]) --right;                     

                }
            }
            while(j+1 < n && nums[j+1] == nums[j]) ++j;
        }
        while(i+1 < n && nums[i+1] == nums[i]) ++i;
    }    
    
    return res;
    
}
