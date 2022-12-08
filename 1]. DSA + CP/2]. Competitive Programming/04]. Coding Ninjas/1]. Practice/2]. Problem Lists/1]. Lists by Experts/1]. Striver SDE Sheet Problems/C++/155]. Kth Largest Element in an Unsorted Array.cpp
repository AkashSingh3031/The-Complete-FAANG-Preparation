#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    return arr[size-K];
}