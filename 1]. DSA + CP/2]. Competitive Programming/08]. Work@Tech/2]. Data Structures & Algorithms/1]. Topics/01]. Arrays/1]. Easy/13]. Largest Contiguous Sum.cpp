/*
Example
    Array: [1, 2, 3, 4, 5]
    Subarrays:
    [1]             => 1
    [2]             => 2
    [3]             => 3
    [4]             => 4
    [5]             => 5
    [1, 2]          => 3
    [2, 3]          => 5
    [3, 4]          => 7
    [4, 5]          => 9
    [1, 2, 3]       => 6
    [2, 3, 4]       => 9
    [3, 4, 5]       => 12
    [1, 2, 3, 4]    => 10
    [2, 3, 4, 5]    => 14
    [1, 2, 3, 4, 5] => 15
*/

int largestContiguousSum(vector <int> &arr){
	int maximumSum = 0, currentSum = 0;
   	int maxValue = INT_MIN, minValue = INT_MAX;
   	
	for (int x: arr) {
       	maxValue = max(maxValue, x);
       	minValue = min(minValue, x);
   	}
	
   	if(maxValue < 0) {
       	return minValue;
   	}
   
	for (int i = 0; i < arr.size(); i++) {
       	currentSum += arr[i];
       	maximumSum = max(maximumSum, currentSum);
       	
		if(currentSum < 0) {
           	currentSum = 0;
       	}
   	}
   	return maximumSum;
}