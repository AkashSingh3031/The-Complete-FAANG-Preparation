public class Solution {
    boolean[][] dp;
    public int solve(int[] a) {
         int sum=0;
                 int n=a.length;
            for(int i=0;i<n;i++)
            sum=sum+a[i];
            dp=new boolean[n+1][sum+1];
            dp[0][0]=true;
            for(int j=0;j<=sum;j++)
            dp[0][j]=false;
            for(int i=0;i<=n;i++)
            dp[i][0]=true;
        helper(a,n,sum);
        int diff=0;
        for(int j=sum/2;j>=0;j--){
            if(dp[n+1][j]==true)
            {
                diff=sum-2*j;
                break;
            }
        }
        return diff;
    }
    public boolean helper(int[]a,int n,int sum){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]<=j)
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
            
        }
        return dp[n][sum];
    }
    
}
