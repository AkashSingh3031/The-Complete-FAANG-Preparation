class Solution {
    public int triangleNumber(int[] nums) {
       Arrays.sort(nums);
        int c=0;
        
        //1.Sort the array
        //2. To make triangle we check sum of 2 sides is greater thena 3rd side or not
    
       for(int i=nums.length-1;i>=0;i--){ 
           int l=0,r=i-1;
           //i have fixed l ,r and i
           //If sum of l+r is coming greater than last element then obviously elements inside l and r will also be able to make triangles 
           while(l<r){
           if(nums[l]+nums[r]>nums[i]){
               c=c+(r-l);
               r--;
           }
               // if sum is coming lesser then do l++
           else{
               l++;
           }
       }
       }
       
        return c;
    }
}