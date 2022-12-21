
 vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
               if(i>0 && (nums[i]==nums[i-1]) )continue;
               int l=i+1, r= n-1;
               while(l<r){
                   int sum =nums[i]+nums[l]+nums[r];
                   
                   if(sum<0) l++;
                   else if(sum>0)r--;
                   else {
                       res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                       while(l+1<r && nums[l]==nums[l+1])l++;
                       while(l<r-1 && nums[r]==nums[r-1]) r--;
                       l++; r--;
                   }
               }
        }
        
        return res;
    }

