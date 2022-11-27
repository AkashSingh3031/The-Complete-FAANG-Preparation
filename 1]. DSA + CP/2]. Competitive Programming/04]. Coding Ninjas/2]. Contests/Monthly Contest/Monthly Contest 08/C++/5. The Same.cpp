/*
    Time Complexity: O(N*N)
    Space Complexity: O(N*N)

    where 'N' is the length of the array.
*/

int helper(int n, vector<int> a, vector<int> p, vector<int> s, vector<vector<int>> dp){

    // Applying base conditions.
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = 1e9;
        }
    }
    for (int i = 0; i < n; i++){
        dp[p[i]][s[i]] = 0;
    }

    // Calculating answer.
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < n; j++){
            if (i > 0 && j < n - 1 && a[i - 1] == a[j + 1]){
                dp[p[i - 1]][s[j + 1]] = min(dp[p[i - 1]][s[j + 1]], dp[i][j] + 1);
            }
            if (i > 0){
                dp[p[i - 1]][j] = min(dp[p[i - 1]][j], dp[i][j] + 1);
            }
            if (j < n - 1){
                dp[i][s[j + 1]] = min(dp[i][s[j + 1]], dp[i][j] + 1);
            }
        }
    }

    // Returning the answer.
    return dp[0][n - 1];
}

int theSame(vector<int> &a){

    int n = a.size();

    // Creating 'p' and 's'.
    vector<int> p(n), s(n);
    p[0] = 0;
    for (int i = 0; i < n; i++){
        if (i != 0 && a[i] == a[i - 1]){
            p[i] = p[i - 1];
        }
        else{
            p[i] = i;
        }
    }
    s[n - 1] = n - 1;
    if (n > 1){
        for (int i = n - 2; i >= 0; i--){
            if (a[i] == a[i + 1]){
                s[i] = s[i + 1];
            }
            else{
                s[i] = i;
            }
        }
    }

    // Creating 'dp'.
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Calling helper function.
    int ans = helper(n, a, p, s, dp);

    // We are returning the answer here.
    return ans;
}