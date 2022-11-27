/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(1)

    where 'N' denotes the number of points.
*/


long long numPoints(int n, vector<int> &x, vector<int> &y) {

    // Sort all the X coordinates.
    sort(x.begin(), x.end());

    // Sort all the Y coordinates.
    sort(y.begin(), y.end());

    /*
     * Count the number of points between the two medians(when 'n' is even),
     * Else if odd, it will be 1, along the X axis.
     * Similarly, count the number of points for the Y axis.
     */
    long long ans = x[n / 2] - x[(n - 1) / 2] + 1;
    ans *= y[n / 2] - y[(n - 1) / 2] + 1;

    // Return the answer 'ans'.
    return ans;
}