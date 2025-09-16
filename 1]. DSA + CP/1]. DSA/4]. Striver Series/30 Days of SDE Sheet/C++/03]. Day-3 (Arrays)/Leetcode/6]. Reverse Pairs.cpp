#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int Merge(vector<int> &num, int low, int mid, int high) {
        int total = 0;
        int j = mid+1;
        for(int i=low; i<=mid; i++) {
            while(j <= high and num[i] > (long long)2 * num[j])
                j++;
            total += (j-(mid+1));
        }
        
        vector<int> t;
        int left = low, right = mid+1;
        
        while(left <= mid and right <= high) {
            if(num[left] <= num[right])
                t.push_back(num[left++]);
            else
                t.push_back(num[right++]);
        }
        while(left <= mid)
            t.push_back(num[left++]);
        while(right <= high)
            t.push_back(num[right++]);
        
        for(int i=low; i<=high; i++)
            num[i] = t[i-low];
        return total;
    }
    
    int MergeSort(vector<int> &nums, int low, int high) {
        if(low >= high) 
            return 0;
        int mid = (low+high)/2;
        int inv = MergeSort(nums, low, mid);
        inv += MergeSort(nums, mid+1, high);
        inv += Merge(nums, low, mid, high);
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size()-1);
    }
};
