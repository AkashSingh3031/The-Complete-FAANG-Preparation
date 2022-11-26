/*
    Time complexity: O( N log N )
    Space complexity: O(1)

    Where 'N' is the size of the arrays 'X' and 'Y'.
*/
#include <vector>
using namespace std;
int MaximumGreatness(int n, vector<int> x, vector<int> y) {

    // An integer variable 'result' to store the answer.
    int result = 0;

    // Sorting the arrays 'X' and 'Y' in non-increasing order.
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    // Integer variable 'ptr1' to move over the array 'X'.
    int ptr1 = 0;
    // Integer variable 'ptr2' to move over the array 'Y'.
    int ptr2 = 0;

    // Iterate as long as 'ptr2' does not reach end of array 'Y'.
    while(ptr2 < n) {

        // If the given condition is satisfied, move both the pointers and increment 'result'.
        if(x[ptr1] > y[ptr2]) {
            result++;
            ptr1++;
            ptr2++;
        }
        // Otherwise, move only the second pointer 'ptr2'.
        else {
            ptr2++;
        }
    }

    // Return 'result' as the final output.
    return result;
}