/*
    Time Complexity: O(N * log(M * MAX))
    Space Complexity: O(1)

    Where 'N' is the number of chefs,
    'M' the number of dishes to make,
    and 'MAX' is the value of the maximum element in 'A'.
*/

#include <vector>
using namespace std;

long long minimumTime(int m, vector<int> &a) {
    
    // Declaring a variable 'N' as the length of the array 'A'.
    int n = a.size();

    // Declaring a variable 'mx' and store the maximum element present in the array 'A'.
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, (long long)a[i]);
    }

    /* Declaring variables 'l' and 'r' as the bounds for binary search 
    and 'ans' for storing the answer. */
    long long l = 1, r = mx * m, ans = mx * m;

    // Running a while loop with condition 'l <= r'.
    while (l <= r) {

        // Declaring a variable 'mid' denoting the time elapsed.
        long long mid = (l + r) / 2;

        /* Declaring a variable 'dishes' and storing 
        the number of dishes made when 'mid' time has elapsed. */
        long long dishes = 0;
        for (int i = 0; i < n; ++i) {
            dishes += mid / a[i];
        }

        /* Assigning 'l' with value 'mid + 1' if 'dishes < M'; 
        otherwise, assigning 'ans' with value 'mid' and 'r' with value 'mid - 1'. */
        if (dishes < m) {
            l = mid + 1;
        }
        else {
            ans = mid;
            r = mid - 1;
        }
    }

    // Returning 'ans'.
    return ans;
}