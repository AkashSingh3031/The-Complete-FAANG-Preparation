public class Solution {
    public int min(int a,int b,int c){
        return Math.min(a,Math.min(b,c));
    }
    public int minDistance(String a, String b) {
        int n=a.length();
        int m=b.length();
        int[][] dp=new int[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i][0]=1+dp[i-1][0];
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=1+dp[0][j-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a.charAt(i-1)==b.charAt(j-1))
                dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
}
