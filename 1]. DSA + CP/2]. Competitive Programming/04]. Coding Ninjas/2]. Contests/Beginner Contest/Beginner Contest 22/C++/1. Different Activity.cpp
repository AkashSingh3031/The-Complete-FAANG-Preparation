/*
    Time Complexity: O(N)
    Space Complexity: O(1)
    Where, 'N' is the number of children.
*/

int makeInnocent(string &a) {
	// Declare 'ans = 0' to store the answer.
	int ans = 0;

	// Declare 'same' to store the number of consecutive students doing same activity as last student.
	int same = 1;

	// Iterate from the second character.
	for (int i = 1; i < a.size(); i++) {
		// If 'a[i] == a[i-1]' increament 'same'.
		if (a[i] == a[i - 1]) {
			same++;
		}
		// If 'same == 3', we must change the last students activity.
		if (same == 3) {
			ans++;
			a[i] = '@';
			same = 1;
		}
	}
	// Return 'ans' as the final answer.
	return ans;
}