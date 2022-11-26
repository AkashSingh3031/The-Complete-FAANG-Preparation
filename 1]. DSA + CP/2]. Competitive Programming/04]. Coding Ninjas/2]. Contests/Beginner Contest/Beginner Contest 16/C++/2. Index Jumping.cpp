/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of the array 'A'.
*/

#include <vector>
using namespace std;

int minimumVisitingCost(vector<int> &a) {
    
    // Declaring 'n' as the length of the array 'a'.
    int n = a.size();

    /* Declaring 'aMin' and 'aMax' for storing the 
    minimum and the maximum value in the array 'a', respectively. */
    int aMin = a[0], aMax = a[0];

    // Iterating over the array 'a' to find the minimum and maximum values.
    for (int i = 0; i < n; ++i) {

        // Updating 'aMin' if the current element 'a[i]' is lesser.
        aMin = min(aMin, a[i]);
        
        // Updating 'aMax' if the current element 'a[i]' is greater.
        aMax = max(aMax, a[i]);
    }

    // Declaring 'ans' with the value of the final answer and then returning it.
    int ans = aMax - aMin + min(aMax - a[0], a[0] - aMin);
    return ans;
}