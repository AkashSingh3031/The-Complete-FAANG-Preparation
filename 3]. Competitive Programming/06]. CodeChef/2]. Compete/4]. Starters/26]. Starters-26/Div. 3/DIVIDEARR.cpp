#include <bits/stdc++.h>
using namespace std;

int help(vector<int>& arr, vector<vector<int>>& dp, int n, int idx, int i, int j) {
    if(idx == n + 1) return 0;
    int &ans = dp[i][j];
    if(ans != -1) return ans;
    ans = 0;
    ans = max(ans, (i > 0 ? abs(arr[idx] - arr[i]) : 0) + help(arr, dp, n, idx + 1, idx, j));
    ans = max(ans, (j > 0 ? abs(arr[idx] - arr[j]) : 0) + help(arr, dp, n, idx + 1, i, idx));

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << help(arr, dp, n, 1, 0, 0) << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}