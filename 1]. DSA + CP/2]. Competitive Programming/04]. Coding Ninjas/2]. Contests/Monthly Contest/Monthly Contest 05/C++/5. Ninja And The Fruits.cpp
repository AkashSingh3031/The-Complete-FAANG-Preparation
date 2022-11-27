/*
    Time complexity: O(3 ^ (N * M))
    Space complexity: O(1)

    Where 'N' and 'M' are the input integers.
*/

// This function will return the number of ways when we have filled till the ith row and jth column from starting from the bottom.

int get(int n, int m, int i, int j, int cur, int prev) {
    
    // Checking the condition if 'i == n'.
    if (i == n) {
        return get(n, m, 0, j + 1, 0, cur);
    }

    // Checking the condition if 'j == m'.
    if (j == m) {
        return 1;
    }

    // Initializing the variables.
    int res = 0, up = (i == 0) ? 0 : (cur >> ((i - 1) * 2)) & 3, left = prev >> (i * 2) & 3;

    // Calling for all the conditions.
    for (int k = 1; k <= 3; ++k) {
        if (k != left && k != up) {
            res = (res + get(n, m, i + 1, j, cur + (k << (i * 2)), prev)) % 1000000007;
        }
    }

    // Returning the 'res'.
    return res;
}

int numberOfWays(int n, int m) {

    return get(n, m, 0, 0, 0, 0);
}