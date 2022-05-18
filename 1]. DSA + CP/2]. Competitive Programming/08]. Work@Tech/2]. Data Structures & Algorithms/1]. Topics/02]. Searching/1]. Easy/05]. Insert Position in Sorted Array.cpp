/*
Example-1:
    Array: [1, 2, 3, 4, 5]
    Number: 3
    Answer: 2

Example-2:
    Array: [1, 2, 3, 5]
    Number: 4
    Answer: 3

Example-3:
    Array: [1, 2, 3, 4, 5]
    Number: -100
    Answer: 0

Example-4:
    Array: [1, 2, 3, 4, 5]
    Number: 6
    Answer: 5
*/

int indx;
int findIndex (vector<int> &arr, int low, int high, int key) {
   	if (high >= low) {
       	int mid = (high + low) / 2;
       	if (arr[mid] == key) {
           	return mid;
       	} 
		else if (arr[mid] < key) {
           	indx = mid;
           	return findIndex (arr, mid + 1, high, key);
       	} 
		else {
           	return findIndex (arr, low, mid - 1, key);
       	}
   	}
   	return indx + 1;
}

int getInsertPosition(vector<int> &arr, int key) {
   	indx = -1;
   	int n = arr.size();
   	return findIndex (arr, 0, n - 1, key);
}