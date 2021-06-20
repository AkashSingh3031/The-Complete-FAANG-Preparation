// Link : https://leetcode.com/problems/find-the-duplicate-number/
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(nums[mid]==nums[mid+1] or nums[mid]==nums[mid-1])return nums[mid];
            else if(nums[mid]<mid+1)h=mid-1;
            else l=mid+1;
        }
        return mid;
    }
};