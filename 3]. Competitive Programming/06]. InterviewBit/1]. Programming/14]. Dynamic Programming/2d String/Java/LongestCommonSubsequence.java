public class Solution {
    
    int[][] dp=new int[1001][1001];
    public int solve(String s1, String s2) {
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++)
                dp[i][j]=-1;
        }
        int n=s1.length();
        int m=s2.length();
        return LCS(s1,s2,n,m);
    }
    public int LCS(String s1,String s2,int n,int m){
        if(n==0||m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s1.charAt(n-1)==s2.charAt(m-1))
            return dp[n][m]=LCS(s1,s2,n-1,m-1)+1;
        else{
            return dp[n][m]=Math.max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
        }
    }
}