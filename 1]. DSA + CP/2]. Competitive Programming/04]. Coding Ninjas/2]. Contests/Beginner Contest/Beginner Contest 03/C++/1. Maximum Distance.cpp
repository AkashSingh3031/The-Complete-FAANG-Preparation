/*
    Time Complexity: O(1)
    Space Complexity: O(1)

*/


int maximumDistance(int n, int m, int x, int y) {

    // Return the value of the formula as mentioned in the editorial.
    return max(x - 1, n - x) + max(y - 1, m - y);
}
