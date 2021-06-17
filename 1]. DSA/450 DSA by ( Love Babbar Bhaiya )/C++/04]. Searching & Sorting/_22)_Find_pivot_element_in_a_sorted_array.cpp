// Find pivot element

// Link : http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/
// In the above link it is mentioned that the array is sorted and rotated,but that need not be the case.This method works fine even for the unsorted array

// you can solve this on leetcode
// Link : https://leetcode.com/problems/find-peak-element/

// A peak element is an element that is strictly greater than its neighbors.

// Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();int mid;
        if(n==1)return 0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid>0 and mid<n-1){
                if(nums[mid-1]<nums[mid] and nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid-1])high=mid-1;
                else low=mid+1;
            }
            else if(mid==0){
                if(nums[mid]>nums[mid+1])return mid;
                else return mid+1;
            }
            else if(mid==n-1){
                if(nums[mid-1]<nums[mid])return mid;
                else return mid-1;
            }
        }
        return mid;
        
    }