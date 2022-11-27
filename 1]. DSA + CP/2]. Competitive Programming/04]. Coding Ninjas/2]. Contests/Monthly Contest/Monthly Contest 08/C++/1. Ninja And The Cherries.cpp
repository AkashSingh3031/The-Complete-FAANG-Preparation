/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the size of the array 'A'.
*/

long long maximumAggregateCount(int n, vector<int> &a) {
    // Initializing the drive variables.
    long long totalSum = 0, currentSum = 0, ans = 0;

    // Calculating the 'totalSum'.
    for (int i = 0; i < n; i++) {
        totalSum += a[i];
    }

    // Iterating over the array.
    for (int i = 0; i < n - 1; i++) {
        currentSum += a[i];
        ans = max(ans, max(currentSum, totalSum - currentSum));
    }

    return ans;
}