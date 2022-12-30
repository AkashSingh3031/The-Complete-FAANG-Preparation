 int removeDuplicates(vector<int>& nums) {    
        int k = 0,n = nums.size();
        
        for(int i=0;i<n;i++){
            int j = i;            
            while(j<n and nums[i]==nums[j]){
                j++;
            }
            nums[k++] = nums[i];
            i = j -1;
        }
        return k;
    }
