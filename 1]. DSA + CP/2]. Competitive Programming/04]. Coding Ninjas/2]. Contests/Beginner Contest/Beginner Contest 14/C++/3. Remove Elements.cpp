/*
	Time Complexity:- O(N)
	Space Complexity:- O(1)
	Here, 'N' is the length of given array 'V'.
*/

int minimumElementsToRemove(int n, vector<char> &v) {

	// Declare 'gone' = 0.
	int gone = 0;

	// Declare and initialize 'rem' to the frequency of 'B' in array 'V'.
	int rem = count(v.begin(), v.end(), 'B');

	// 'ans' = 'n' because we can always delete all the elements.
	int ans = n;

	// iterate all elements.
	for (int i = 0; i < n; i++) {
		if (v[i] == 'A') {
			gone++;
		}

		// At current point ('gone' + 'rem') elements can form a array which follows the condition.
		// So, 'n' - ('gone'+'rem') to be deleted.
		ans = min(ans, n - (gone + rem));


		if (v[i] == 'B') {
			rem--;
		}
	}

	// Return ans.
	return ans;
}