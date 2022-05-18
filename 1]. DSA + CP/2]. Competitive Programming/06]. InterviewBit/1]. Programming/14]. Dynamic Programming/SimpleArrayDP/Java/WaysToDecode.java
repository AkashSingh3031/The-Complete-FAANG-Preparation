public class Solution {
    public int numDecodings(String s) {
                if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = s.charAt(0) != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            int first = Integer.valueOf(s.substring(i - 1, i));
            int second = Integer.valueOf(s.substring(i - 2, i));
            if (first >= 1 && first <= 9) {
               dp[i] =(dp[i]+dp[i-1])%1000000007;  
            }
            if (second >= 10 && second <= 26) {
                dp[i] =(dp[i]+dp[i-2])%1000000007;
            }
        }
      return (int)(dp[n]%1000000007);
    }
}
