/*
	Time Complexity:- O(N * log(A_MAX))
	Space Complexity:- O(1)
	Here, 'N' is the number of element in array, and 'A_MAX' is the value of maximum element in array 'A'.

*/

int makeQualityArray(vector<int> &a) {
	int ans = 0;

	// Iterate through every element and increase 'ans' if we encounter an element which is not good.
	for (int i = 0; i < a.size(); i++) {
		if (a[i] % 2) {
			// Current element doesn't have an even divisor.
			ans++;
		}
		else {
			while (a[i] % 2 == 0) {
				a[i] /= 2;
			}
			if (a[i] == 1) {
				// Current element is a power of 2 so it doesn't have an odd divisor.
				ans++;
			}
		}
	}
	return ans;
}