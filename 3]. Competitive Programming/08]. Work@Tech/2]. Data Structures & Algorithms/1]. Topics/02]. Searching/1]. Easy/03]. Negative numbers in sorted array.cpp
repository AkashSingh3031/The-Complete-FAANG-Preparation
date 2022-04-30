/*
Example-1:
    Array: [-5, -3, -2, 3, 4, 6, 7, 8]
    Answer: 3

Example-2:
    Array: [0, 1, 2, 3, 4, 6, 7, 8]
    Answer: 0
*/

int binarySearch (vector<int> arr, int low, int high) {
   	if (high > low) {
       	int mid = (high + low) / 2;
		
       	if (arr[mid] < 0 && arr[mid + 1] >= 0) {
           	return mid;
       	} 
		else if (arr[mid] >= 0 && arr[mid + 1] >= 0) {
           	return binarySearch(arr, 0, mid);
       	} 
		else {
           	return binarySearch(arr, mid + 1, high);
       	}
   	}
   	return -1;
}

int getNegativeNumbersCount(vector<int> &arr) {
   	if (arr[0] >= 0) {
		return 0;
	}
   	if (arr[arr.size()-1] < 0) {
		return arr.size();
	}
   	return binarySearch (arr, 0, arr.size() - 1) + 1; //index + 1
}