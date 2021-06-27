public class Solution {
    int[][] dp;
   public int solve(int e, int f) {
       dp=new int[e+1][f+1];
       for(int i=0;i<=e;i++){
           for(int j=0;j<=f;j++)
               dp[i][j]=-1;
       }
      return helper(e,f);
   }
   int helper(int e,int f){
       if(f==0|| f==1)
           return f;
       if(e==1)
           return f;
       if(dp[e][f]!=-1)
           return dp[e][f];
       
               int low = 1, high = f, result = f;
       while (low < high) {
           int mid = low + (high - low) / 2;
           int left = helper(e - 1, mid - 1);
           int right = helper(e, f - mid);
           result = Math.min(result, Math.max(left, right) + 1);
           if (left == right) {
               break;
           } else if (left < right) {
               low = mid + 1;
           } else {
               high = mid;
           }
       }
       dp[e][f] = result;
       return result;
   }
}
