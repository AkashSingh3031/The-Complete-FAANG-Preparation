

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i =0; i < nums.size(); i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(int i =0; i < nums.size(); i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};