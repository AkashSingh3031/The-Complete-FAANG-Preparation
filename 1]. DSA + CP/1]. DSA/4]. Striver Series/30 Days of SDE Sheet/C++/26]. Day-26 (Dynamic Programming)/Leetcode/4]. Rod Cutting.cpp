class Solution {
public:
    int minCost(int n, vector<int>& A) {
        A.push_back(0);
        A.push_back(n);
        sort(A.begin(), A.end());
        int k = A.size();
        vector<vector<int>> dp(k, vector<int>(k));
        for (int d = 2; d < k; ++d) {
            for (int i = 0; i < k - d; ++i) {
                dp[i][i + d] = 1e9;
                for (int m = i + 1; m < i + d; ++m) {
                    dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + A[i + d] - A[i]);
                }
            }
        }
        return dp[0][k - 1];
    }
};