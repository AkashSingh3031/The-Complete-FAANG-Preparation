/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

int contiguousBlocks(int r, int g, int b) {
	// Find the minimum and maximum among the given 3 value.
	int mx = max(r, max(g, b));
	int mn = min(r, min(g, b));

	// If the difference between 'mx' and 'mn' is greater than 1, it is impossible to find any contigouos blocks.
	if (mx - mn > 1) {
		return -1;
	}
	// Otherwise, we can find blocks that follow the condition.
	return 1;
}