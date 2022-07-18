#include<bits/stdc++.h>

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<int> dp(n,-1);
    dp[0] = rack[0];
    
    for(int i=1;i<n;i++)
    {
        int ans = rack[i];
        for(int j=0;j<i;j++)
        {
            if(rack[j]<rack[i])
            {
                ans = max(ans,rack[i]+dp[j]);
            }
        }
        dp[i] = ans;
    }
    return *max_element(dp.begin(),dp.end());
}