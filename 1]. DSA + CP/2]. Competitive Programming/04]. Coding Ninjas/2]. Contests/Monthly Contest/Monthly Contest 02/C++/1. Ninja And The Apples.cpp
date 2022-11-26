/*
    Time complexity: O(1)
    Space complexity: O(1)
*/

int possibleArrangements(int a, int b, int c) {
    // Intializing the variable 'p'.
    int p = max(0, (c + b - a + 2) / 2);
    return max(0, c - p + 1);
}
