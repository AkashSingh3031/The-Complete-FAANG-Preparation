/*
Example-1:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: 3
    Answer: [2, 4]

Example-2:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: 5
    Answer: [7, 7]

Example-3:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: 6
    Answer: [-1, -1]
*/

int findStart(vector<int> arr, int low, int high, int key) {
   	if (high >= low) {
       	int mid = (high + low) / 2;
		
       	if ((mid == 0 || key > arr[mid - 1]) && arr[mid] == key) {
           	return mid;
       	} 
		else if (key > arr[mid]) {
           	return findStart (arr, mid + 1, high, key);
       	} 
		else {
           	return findStart (arr, low, mid - 1, key);
       	}
   	}
   	return - 1;
}

int findEnd(vector<int> arr, int low, int high, int key, int n) {
   	if (high >= low) {
       	int mid = (high + low) / 2;
		
       	if ((mid == n - 1 || key < arr[mid + 1]) && arr[mid] == key) {
           	return mid;
       	} 
		else if (key < arr[mid]) {
           	return findEnd (arr, low, mid - 1, key, n);
       	} 
		else {
           	return findEnd (arr, mid + 1, high, key, n);
       	}
   	}
   	return - 1;
}

vector<int> searchRange(vector<int> &arr, int key) {
   	int n = arr.size();
   	vector<int> indexes = {findStart (arr, 0, n - 1, key), findEnd (arr, 0, n - 1, key, n)};
   	return indexes;
}