
public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int lis(final int[] A) {
        int n=A.length;
        int[] dp=new int[n];
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            int temp=0;
            for(int j=0;j<i;j++){
                if(A[i]>A[j])
                temp=Math.max(temp,dp[j]);
            }
            dp[i]=temp+1;
            ans=Math.max(ans,dp[i]);
        }
        return ans;
    }
}