/*
Sample Input:
    2                    // Test Case Number
    5 4 2 5 3 1
    3 11 4 200
Expected Output:
    1 2 3 4 5
    4 11 200
*/

void insertionSort(vector<int> &arr) {
    // add your logic here
   	int n = arr.size();
   	for (int i = 1; i < n; i++) {
       	int currentElement = arr[i];
       	int position = i - 1;
       	while (position >= 0 && arr[position] > currentElement) {
           	arr[position + 1] = arr[position];
           	position--;
       	}
       	arr[position + 1] = currentElement;
   	}
}