/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of the array 'A'.
*/

#include <vector>
using namespace std;

long long energyConsumed(vector<int> &a) {
    
    // Declaring a variable 'n' as the length of the array 'A'.
    int n = a.size();

    // Declaring a variable 'ans' for storing the final answer.
    long long ans = 0;

    // Running a loop for iterating over the array 'A'.
    for (int i = 1; i < n; ++i) {

        // Adding 'A[i] - A[i - 1]' to 'ans' if the condition 'A[i] > A[i - 1]' is fulfilled.
        if (a[i] > a[i - 1]) {
            ans += a[i] - a[i - 1];
        }
    }

    // Returning the final answer stored in 'ans'.
    return ans;
}