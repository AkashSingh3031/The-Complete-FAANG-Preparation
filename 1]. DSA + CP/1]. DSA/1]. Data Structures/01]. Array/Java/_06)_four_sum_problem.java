class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res=new ArrayList<>();
        if(nums.length==0 || nums==null )return res;
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                int sum=nums[i]+nums[j];
                int newtarget=target-sum;
                int left=j+1;
                int right=nums.length-1;
                while(left<right){
                    int twosum=nums[left]+nums[right];
                    if(twosum<newtarget){
                        left++;
                    }
                    else if(twosum>newtarget){
                        right--;
                    }
                    else{
                        List<Integer> li=new ArrayList<>();
                        li.add(nums[i]);
                        li.add(nums[j]);
                        li.add(nums[left]);
                        li.add(nums[right]);
                        res.add(li);
                        
                        while(left<right && nums[left]==li.get(2) ) left++;
                        
                        while(left<right && nums[right]==li.get(3)) right--;
                    }
                }
                while(j+1<nums.length && nums[j]==nums[j+1]) j++;
            }
            
            while(i+1<nums.length && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
}