/*
   GFG problem link:-  https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
   Approach:- Kadane's Algorithm
*/

/*
    Input: 
        5
        1
        2
        3
        -2
        5

    Output:
        9
*/

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &arr, int n){
    // Your code here
    long long sum=0, ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0) sum=0;
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) cin>>arr[i];
    cout<<maxSubarraySum(arr,n)<<endl;
    return 0;
}