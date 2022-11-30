/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the length of an input array 'A'.
*/

int isAchievable(int n, vector<int> a) {
    // Iterating over an array 'A'.
    for (int i = 0; i < n; i++) {
        // If 'A[i]' is not divisible by 'A[0]'.
        if (a[i] % a[0] != 0) {
            return 0;
        }
    }

    return 1;
}