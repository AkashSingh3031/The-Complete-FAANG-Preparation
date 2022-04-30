/*
Example-1:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: 2
    Answer: true

Example-2:
    Array: [1, 2, 3, 3, 3, 4, 4, 5]
    Number: 6
    Answer: false
*/

bool binarySearch(vector<int> arr, int low, int high, int key) {
	if(high >= low) {
        int mid = (high + low) / 2;
		
        if (arr[mid] == key)
            return true;
    	else if (arr[mid] < key)
           	return binarySearch (arr, mid + 1, high, key);
       	else
           	return binarySearch (arr, low, mid - 1, key);
   	}
   	return false;
}

bool containsElement(vector<int> &arr, int key) {
   	int n = arr.size();
   	return binarySearch (arr, 0, n - 1, key);
}