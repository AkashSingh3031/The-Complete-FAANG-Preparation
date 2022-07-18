int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(j>=weights[i-1]){
                int remCap=j-weights[i-1];
                if(dp[i-1][remCap]+values[i-1]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][remCap]+values[i-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}