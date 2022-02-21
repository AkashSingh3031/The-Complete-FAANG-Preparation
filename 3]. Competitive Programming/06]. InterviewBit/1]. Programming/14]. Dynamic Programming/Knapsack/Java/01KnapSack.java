public class Solution {
    public int solve(int[] v, int[] w, int s) {
                    long[][] dp=new long[1001][1001];
            for(int i=0;i<1001;i++)
                dp[0][i]=0;
            
            int n=v.length;
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=s;j++){
                    if(j>=w[i-1]){
                        dp[i][j]=Math.max(dp[i-1][j],(dp[i-1][j-w[i-1]]+v[i-1]));
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return (int)dp[n][s];
    }
}
