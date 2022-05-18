/*
Examples-1:
    Initial Array: [1, 2, 3, 4]
    Cumulative Sum: [1, 3, 6, 10]

Examples-2:
    Initial Array: [1, 1, 1, 1, 1]
    Cumulative Sum: [1, 2, 3, 4, 5]

Examples-3:
    Initial Array: [1, 3, 5, 7, 9]
    Cumulative Sum: [1, 4, 9, 16, 25]
*/

vector<int> getCumulativeSum(vector<int> &arr) {
   vector<int> cumulativeSum(n);
   cumulativeSum[0] = arr[0];
   for (int i = 1; i < arr.size(); i++) {
       cumulativeSum[i] = cumulativeSum[i - 1] + arr[i];
   }
   return cumulativeSum;
}