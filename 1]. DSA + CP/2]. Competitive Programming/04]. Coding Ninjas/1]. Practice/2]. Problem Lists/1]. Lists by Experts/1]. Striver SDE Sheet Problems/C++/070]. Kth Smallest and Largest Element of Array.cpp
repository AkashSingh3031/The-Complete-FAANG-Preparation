#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<int> res;
    res.push_back(arr[k-1]);
    res.push_back(arr[n-k]);
    return res;
}