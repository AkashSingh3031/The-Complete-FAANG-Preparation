#include<bits/stdc++.h>
int solve(string target, vector<string>& arr, unordered_map<string, int>& dp){
    int n = target.size();
    if(n==0) return 1;
    if(dp[target]!=0) return dp[target];
   
    for(int i=1;i<n+1;i++){
        string str = target.substr(0, i);
        int flag = 0;
        for(int j=0;j<arr.size();j++){
            if(str.compare(arr[j])==0){
                flag = 1;
                break;
            }
        }
        if(flag==1 and solve(target.substr(i, n-i), arr, dp)==1) return dp[target] = 1;
    }
    return dp[target] = -1;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_map<string, int> dp;
    int x = solve(target, arr, dp);
    if(x==1) return 1;
    return 0;
}