/*
Examples-1:
    Array: [9, 13, 5, 15, 7, 11]
    Answer: true
  Explanation: This can be reordered to [5, 7, 9, 11, 13, 15] or [15, 13, 11, 9, 7, 5] both of which are arithmetic sequences.

Example-2:
    Array: [1, 1, 1]
    Answer: true
  Explanation: This is an arithmetic sequence with a difference 0.
*/

bool isArithmeticSequence(vector<int> &arr) {
    // add your logic here
	int n = arr.size();
   	if (n == 1) {
       	return true;
   	}
       
   	sort(arr.begin(), arr.end());
   	int commonDiff = arr[1] - arr[0];
   	for (int i = 1; i < n; i++) {
       	if (arr[i] - arr[i - 1] != commonDiff) {
           	return false;
       	}
   	}
   	return true;
}