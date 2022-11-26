/*
    Time Complexity: O(N * M)
    Space Complexity: O(1)

    where 'N' is the number of rows, and 'M' is the
    number of columns in the matrix 'A' respectively.
*/

#include <vector>
using namespace std;

int isAlternatingPossible(int n, int m, vector<vector<char>> &a) {

    // 'ok' stores whether the matrix can be an alternating matrix or not.
    bool ok = true;

    // Iterate over the rows of the matrix.
    for (int i = 0; i < n; ++i) {

        // Iterate over the columns of the matrix.
        for (int j = 0; j < m; ++j) {

            // If it should be a 'R' cell, but it's a 'B' cell, or vice-versa.
            if (((i + j) % 2 == 0 && a[i][j] == 'B') || ((i + j) % 2 && a[i][j] == 'R')) {

                // Set 'ok' to false and break.
                ok = false;
                break;
            }
        }
    }

    // If 'ok' is true, it means, matrix 'a' matches the first alternating matrix.
    if (ok) {

        // So, return the integer 1.
        return 1;
    }

    // Now, 'ok' would be false, so set it to true again.
    ok = true;

    // Iterate over the rows of the matrix.
    for (int i = 0; i < n; ++i) {

        // Iterate over the columns of the matrix.
        for (int j = 0; j < m; ++j) {

            // If it should be a 'B' cell, but it's a 'R' cell, or vice-versa.
            if (((i + j) % 2 == 0 && a[i][j] == 'R') || ((i + j) % 2 && a[i][j] == 'B')) {

                // Set 'ok' to false and break.
                ok = false;
                break;
            }
        }
    }

    // If 'ok' is true, it means, matrix 'a' matches the second alternating matrix.
    if (ok) {

        // So, return the integer 1.
        return 1;
    }

    // Matrix 'a' did not match any of the two alternating matrices, so return 0.
    return 0;
}