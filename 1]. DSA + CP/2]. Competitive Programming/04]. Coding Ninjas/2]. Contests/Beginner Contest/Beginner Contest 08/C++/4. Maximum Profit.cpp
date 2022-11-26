/*
	Time Complexity: O(N * log N)
	Space Complexity: O(1)

	where ‘N’ is the number of packages.
*/

long long int maximumProfit(int n, int k, vector<int> a)
{
	// Initialize ans as 0.
	long long int ans = 0;

	// Sort the given array.
	sort(a.begin(), a.end());

	// Greedily pick the largest k values and add them to ans.
	for(int i = n - k; i < n; i++)
		ans += a[i];


	// Return the answer.
	return ans;
}