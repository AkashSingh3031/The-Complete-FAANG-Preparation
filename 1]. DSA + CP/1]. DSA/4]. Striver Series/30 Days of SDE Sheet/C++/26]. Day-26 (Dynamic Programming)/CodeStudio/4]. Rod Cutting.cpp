#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int dp[n];
    dp[0]=price[0];
    for(int i=1;i<n;i++)
    {
        int m=price[i];
        for(int j=i-1;j>=0;j--)
        {
            m=max(price[i-j-1]+dp[j],m);
        }
        dp[i]=m;
    }
    return dp[n-1];
}