/*
'''
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
'''
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (auto i : nums2)
            nums1.push_back(i);

        sort(begin(nums1), end(nums1));

        for (auto i : nums1)
            cout << i << " ";

        int size = nums1.size() - 1;

        if (size % 2 == 0)
            return nums1[size / 2];
        else
            return (nums1[size / 2] + nums1[size / 2 + 1]) / 2.0;
        return 0;
    }
};