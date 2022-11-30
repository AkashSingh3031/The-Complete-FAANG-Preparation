/*
	Time Complexity:- O(N)
	Space Complexity:- O(N)
	Here, 'N' is the length of string 'S'.

*/


string findStableNumber(int k, string &s) {

	// Store the size of 's' in a variable 'n'.
	int n = s.size();

	// Create a string 'currStable' where, 'currStable[i]' = 's[i%k]' for all 'i' from 0 to 'n-1'.
	string currStable = "";
	for (int i = 0; i < n; i++) {
		currStable += s[i % k];
	}

	// If 'currStable' is greater or equal to 's' return it.
	if (currStable >= s) {
		return currStable;
	}

	// Find the last index among the first 'k' digits where the digit is not '9' and increase it.
	int ind = k - 1;
	while (currStable[ind] == '9') {
		currStable[ind] = '0'; ind--;
	}
	currStable[ind]++;

	// Create the full answer by making the newly created 'currStable' stable.
	for (int i = 0; i < n; i++) {
		currStable[i] = currStable[i % k];
	}

	return currStable;
}