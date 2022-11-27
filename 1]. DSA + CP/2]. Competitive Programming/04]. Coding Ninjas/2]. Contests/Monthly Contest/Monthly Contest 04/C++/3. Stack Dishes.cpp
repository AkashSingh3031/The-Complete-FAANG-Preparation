/*
    Time Complexity: O(N)
    Space Complexity: O(N)
    
    where 'N' is the number of dishes we have in total.
*/

int minStackOfDishes(int n, vector<int> &a) {
	
    // Declare 'freq', which will be a hash table.
	unordered_map<int, int> freq;

	// Declare 'ans' to keep track of maximum frequency till now.
	int ans = 0;

	// Iterate all elements of 'a'.
	for (int i = 0; i < n; i++) {

		// Increase the frequency of 'a[i]'.
		freq[a[i]]++;

		// Update the 'ans'.
		ans = max(ans, freq[a[i]]);
	}
	return ans;
}