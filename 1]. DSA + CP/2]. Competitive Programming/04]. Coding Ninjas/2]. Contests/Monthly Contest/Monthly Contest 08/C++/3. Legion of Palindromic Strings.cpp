/*
	Time Complexity:- O(N*M)
	Space Complexity:- O(1)
	Here, 'N' is the number of strings given and 'M' is the length of each string.

*/
int isPalindromicLegion(vector<string>&s) {

	// Declare, 'n' and 'm', assign them values as per the problem statement.
	int n = s.size();
	int m = s[0].size();


	// Traverse the strings characterwise.
	// In a string 'j' and 'm-j-1' will be mirror index as the character in that index need to be same if string is palindrome.

	for (int j = 0; j < m / 2; j++) {
		// We need to go only till 'm/2 - 1' because every index will be covered.

		int fromBegin = j, fromEnd = m - j - 1;

		// Declare, two array of size 26 to store frequency of the character.
		vector<int>left(26, 0), right(26, 0);

		for (int i = 0; i < n; i++) {
			left[s[i][fromBegin] - 'a']++;
			right[s[i][fromEnd] - 'a']++;
		}

		// If the frequency are not the same then all strings can't be palindrome.
		if (left != right) {
			return -1;
		}
	}
	return 1;
}