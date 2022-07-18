#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> res;
    for(int i=0; i<n; i++) {
        auto it = std::lower_bound(res.begin(), res.end(), arr[i]);
        if(it==res.end()) res.push_back(arr[i]);
        else *it = arr[i];
    }
    return res.size();
}