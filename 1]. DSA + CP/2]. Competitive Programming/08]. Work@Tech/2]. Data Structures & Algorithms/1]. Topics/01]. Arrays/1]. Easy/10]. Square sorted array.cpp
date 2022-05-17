/*
Example:
    Array: [6, -8, 3, -1, 4]
    Answer: [1, 9, 16, 36, 64]
*/

vector<int> getSquareSortedArray(vector<int> &arr) {
    // add your logic here
	for (int i = 0; i < arr.size(); i++) {
       	arr[i] *= arr[i];
   	}
   	sort (arr.begin(), arr.end());
   	return arr;
}