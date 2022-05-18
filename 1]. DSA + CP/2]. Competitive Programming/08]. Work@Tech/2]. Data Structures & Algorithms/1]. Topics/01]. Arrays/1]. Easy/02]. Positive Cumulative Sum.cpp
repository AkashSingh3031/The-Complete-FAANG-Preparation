/*
Examples-1:
    Initial Array: [1, -2, 3, 4, -6]
    Cumulative Sum: [1, -1, 2, 6, 0]

Examples-2:
    Initial Array: [1, -1, -1, -1, 1]
    Cumulative Sum: [1, 0, -1, -2, -1]

Examples-3:
    Initial Array: [1, 3, 5, 7]
    Cumulative Sum: [1, 4, 9, 16]
*/

vector<int> getPositiveCumulativeSum(vector<int> &arr) {
	// add your logic here
	vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    vector<int> positivePrefix;
    for (int i = 0; i < arr.size(); i++) {
        if(prefix[i] > 0) {
            positivePrefix.push_back(prefix[i]);
        }
    }
    return positivePrefix;
}