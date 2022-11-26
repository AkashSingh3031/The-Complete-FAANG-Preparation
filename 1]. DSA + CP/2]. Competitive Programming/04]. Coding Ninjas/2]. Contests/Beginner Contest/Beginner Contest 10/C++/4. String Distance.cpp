/*
    Time Complexity: O(N * M)
    Space Complexity: O(N * M)

    where 'N' and 'M' denotes the length of the string 'S',
    and the string 'T' respectively.
*/

int minimumStringDistance(string s, string t, int k) {

    // 'n' is the length of the string 's' and 'm' is the length of string 't'.
    int n = s.length(), m = t.length();

    /*
     * 'dp[i][j]' stores the minimum string distance if
     *  we consider the prefix [0, 'i - 1'] of the string 's' and
     *  the prefix [0, 'j - 1'] of the string 't'.
     */
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Taking the prefix [0, 'i - 1'] of the string 's' and empty prefix of the string 't'.
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i * k;
    }

    // Taking the prefix [1, 'j - 1'] of the string 't' and empty prefix of the string 's'.
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j * k;
    }

    // Iterate over the prefix of 's'.
    for (int i = 1; i <= n; ++i) {

        // Iterate over the prefix of 't'.
        for (int j = 1; j <= m; ++j) {

            /*
             * 3 cases:
             * Combine 's[i - 1]' with a space character,
             * Combine 't[j - 1]' with a space character,
             * or combine both 's[i - 1]' and 't[j - 1]' together.
             */
            dp[i][j] = min({dp[i - 1][j] + k, dp[i][j - 1] + k, dp[i - 1][j - 1] + abs(s[i - 1] - t[j - 1])});
        }
    }

    // Return the answer 'dp[n][m]'.
    return dp[n][m];
}
