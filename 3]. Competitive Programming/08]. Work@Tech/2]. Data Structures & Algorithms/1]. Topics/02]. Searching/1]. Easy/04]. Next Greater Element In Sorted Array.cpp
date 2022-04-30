/*
Example-1:
    Array: [1, 2, 3, 3, 4, 4, 8, 10]
    Number: 4
    Answer: 8

Example-2:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: 5
    Answer: 5 (Largest Element)

Example-3:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: -5
    Answer: 1
*/

int binarySearch (vector<int> &arr, int low, int high, int key) {
	if(low < high) {
		int mid = (high + low) / 2;
		
		if (arr[mid] <= key) {
			return binarySearch (arr, mid + 1, high, key);
		} 
		else {
			return binarySearch (arr, low, mid, key);
		}
	}
	else {
		return arr[low];
	}
}

int getNextGreaterElement(vector<int> &arr, int key) {
    int n = arr.size();
	if (arr[n - 1] <= key) {
		return key;
	}
	return binarySearch (arr, 0, n - 1, key);
}