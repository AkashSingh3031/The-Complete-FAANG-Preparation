#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*
Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

Example 2:
    Input: nums = []
    Output: []

Example 3:
    Input: nums = [0]
    Output: []
*/

class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n<3) return result;

        for(int i=0 ; i<n-2 ; ++i) {
            if(i==0 || nums[i]!=nums[i-1]) {
                int low = i+1;
                int high = n-1;
                int sum = 0 - nums[i];

                while(low < high) {
                    if((nums[low] + nums[high]) == sum) {
                        result.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low]==nums[low+1]) 
                            low++;
                        while(low<high && nums[high]==nums[high-1]) 
                            high--;
                        low++;
                        high--;
                    }
                    else if((nums[low] + nums[high]) > sum)
                        high--;
                    else 
                        low++;
                }
            }
        }
    return result;
    }

};