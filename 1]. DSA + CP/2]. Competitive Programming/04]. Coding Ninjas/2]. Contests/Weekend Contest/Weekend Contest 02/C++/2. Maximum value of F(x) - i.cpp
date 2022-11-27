/*
	Time complexity: O(log(N))
	Space complexity: O(1)
	
	Where 'N' is the length of 'ARR'.
*/

int lowerBound(vector<int> &arr, int n, int x) {
	int l = -1, r = n;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (arr[m] >= x) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}

int maxFXI(int n, vector<int> &arr, int k){
	// Taking lower bound of 'k' in 'arr'.
	int lower = lowerBound(arr, n, k);

	// Variable to hold the required 'x'.
	int x;

	// Check the edge cases.
	if (lower == arr.size()){
		x = arr[n - 1];
		return (2 * k) / (1 + 2 * abs(x - k));
	}
	else if (lower == 0){
		x = arr[0];
		return (2 * k) / (1 + 2 * abs(x - k));
	}

	x = arr[lower];
	int m = (2 * k) / (1 + 2 * abs(x - k));
	x = arr[lower - 1];
	m = max(m, (2 * k) / (1 + 2 * abs(x - k)));
	return m;
}
