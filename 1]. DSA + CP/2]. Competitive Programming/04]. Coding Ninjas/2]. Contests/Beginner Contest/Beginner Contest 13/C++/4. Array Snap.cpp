/*
    Time Complexity: O(K + N*N)
    Space Complexity: O(K+N).

    'K' is the number of operations to perform, and 'N' is the length of the given array.
*/

int waysToTransform(int n, int k, vector<int> &a, vector<int>&b) {
	int goodShift = 0, badShift = 0;

	// calculate 'goodShift' and 'badShift' as mentioned in approach 1.

	for (int i = 0; i < a.size(); i++) {
		int curr = i;
		vector<int>nw;

		while (nw.size() < a.size()) {
			nw.push_back(a[curr]);
			curr++;
			curr %= a.size();
		}

		if (nw == b) {
			goodShift++;
		}
		else {
			badShift++;
		}
	}
	// Create and initialize 'dp' table with 0.
	vector<vector<long long>>dp(2, vector<long long>(k + 1, 0));

	const long long mod = 1e9 + 7;
	if (a == b) {
		// if initial state is good then.
		dp[1][0] = 1; dp[0][0] = 0;
	}
	else {
		dp[0][0] = 1;
		dp[1][0] = 0;
	}

	for (int i = 1; i <= k; i++) {
		// perform the transition as mentioned in approach.
		dp[0][i] = ((dp[0][i - 1] * (badShift - 1)) % mod + (dp[1][i - 1] * (badShift))) % mod;
		dp[1][i] = ((dp[0][i - 1] * (goodShift)) % mod + (dp[1][i - 1] * (goodShift - 1))) % mod;
		// keep performing modulo with 'mod'.
	}
	// return 'dp[1][k]'.
	return dp[1][k];
}