/*
    Time Complexity: O(NlogN)
    Space Complexity: O(N).

    Where 'N' is the number of pits given.
*/

long long collectCoins(int k, vector<int> &p, vector<int>&c) {

	int n = p.size();

	// Declare 'v', to sort the pits based on their position.
	vector<pair<int, int>>v;

	// Declare 'dp', to store the answer for all position.
	vector<long long>dp(p.size(), 0LL);
	for (int i = 0; i < p.size(); i++) {
		v.push_back(make_pair(p[i], c[i]));
	}
	// Sort the pits based on their 'p[i]' value.
	sort(v.begin(), v.end());


	// Calculate maximum coins we can collect and get to position 'i', store it in 'dp[i]'.
	// Note, that currently we haven't included the coins of 'ith' pit.
	for (int i = 0; i < n; i++) {
		if (i - 1 > -1) {
			dp[i] = max(dp[i], dp[i - 1]);
		}

		// Calculate the 'nextPit' we can visit if we jump from the current pit.
		auto nextPit = upper_bound(v.begin(), v.end(), make_pair(v[i].first + k, 0));
		auto nextPitInd = nextPit - v.begin();

		if (nextPitInd < n) {
			// Add the coins of current pit into the next pits 'dp' value.
			dp[nextPitInd] = max(dp[i] + v[i].second, dp[nextPitInd]);
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		// Now, add the coins of 'ith' pit into 'dp[i]' value.
		ans = max(dp[i] + v[i].second, ans);
	}
	return ans;
}
