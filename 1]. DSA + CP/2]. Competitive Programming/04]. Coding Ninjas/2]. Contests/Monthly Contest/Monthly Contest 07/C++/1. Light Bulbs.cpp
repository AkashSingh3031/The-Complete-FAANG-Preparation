/*
	Time Complexity:- O(N)
	Space Complexity:- O(1)
	Here, 'N' is the number of bulbs given.

*/
int removeBulbs(vector<int> &a) {
	int n = a.size();

	// Store the index for first and last bulb that is ON.
	int firstOn = -1, lastOn = -1;

	// Iterate through front for the first bulb.
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			// Break after finding the first ON bulb, and store index in 'firstOn'.
			firstOn = i; break;
		}
	}

	// Iterate through end to find the last ON bulb.
	for (int i = n - 1; i > -1; i--) {
		if (a[i] == 1) {
			// Break after finding the last ON bulb, and store index in 'lastOn'.
			lastOn = i; break;
		}
	}

	// Declare, 'toRemove = 0' to store the answer.
	int toRemove = 0;

	// If 'firstOn = -1', there are no bulbs that are ON so answer is 0.
	if (firstOn != -1) {
		// Go from first to last, and count the number of OFF bulb.
		for (int j = firstOn; j <= lastOn; j++) {
			if (a[j] == 0) {
				// Add one when we find the OFF bulb.
				toRemove++;
			}
		}
	}
	return toRemove;
}