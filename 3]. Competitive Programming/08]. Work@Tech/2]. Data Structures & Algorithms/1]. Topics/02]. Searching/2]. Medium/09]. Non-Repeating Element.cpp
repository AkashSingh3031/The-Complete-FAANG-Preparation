/*
Example:
    1, 1, 2, 3, 3, 4, 4
    Here, ‘2’ appears once and all other elements appear twice.

    findNonRepeatingElement([1, 1, 2, 3, 3, 4, 4]) => 2
*/

int findNonRepeatingElement(vector<int> &arr) {
    // add your logic here
	int n = arr.size();
   	int arrXor = 0;
   	for (int i = 0; i < n; i++) {
       	arrXor = arrXor ^ arr[i];
   	}
   	return arrXor;
}