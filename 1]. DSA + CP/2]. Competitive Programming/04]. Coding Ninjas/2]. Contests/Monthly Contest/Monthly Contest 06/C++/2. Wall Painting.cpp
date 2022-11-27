/*
    Time Complexity: O(N + M)
    Space Complexity: O(1)

    where 'N' is the number of rows, and 'M' is the number of columns.
*/

#include <vector>
using namespace std;

int wallPainting(vector<vector<int>> &a) {

    // Defining the variables 'N' denoting the number of rows, and 'M' denoting the number of columns.
    int n = a.size(), m = a[0].size();

    // Returning '1' as the answer if one of the corner cells is a good cell.
    if (a[0][0] or a[0][m - 1] or a[n - 1][0] or a[n - 1][m - 1]) {
        return 1;
    }

    // Returning '2' as the answer if one of the edge cells is a good cell.
    for (int i = 1; i < n - 1; ++i) {
        if (a[i][0] or a[i][m - 1]) {
            return 2;
        }
    }
    for (int i = 1; i < m - 1; ++i) {
        if (a[0][i] or a[n - 1][i]) {
            return 2;
        }
    }

    // Returning '4' as the answer for the remaining cases.
    return 4;
}