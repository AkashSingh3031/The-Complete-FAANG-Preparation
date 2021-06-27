public class Solution {
    boolean[][] dp;
    public int solve(int[] a, int sum) {

            int n=a.length;
            dp=new boolean[n+1][sum+1];
            dp[0][0]=true;
            for(int j=0;j<=sum;j++)
            dp[0][j]=false;
            for(int i=0;i<=n;i++)
            dp[i][0]=true;
        if(helper(a,n,sum)==true)
        return 1;
        else
        return 0;

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
