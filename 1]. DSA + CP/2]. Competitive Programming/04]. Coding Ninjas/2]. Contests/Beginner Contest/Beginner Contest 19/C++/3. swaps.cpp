/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(1)
    Where 'N' is the length of the array 'A'.
*/

#include <vector>
#include<iostream>    
#include<algorithm>
using namespace std;
vector<int> swaps(int n, vector<int>& a) {

    // Initialise bool variable 'isTwoParity', to check if elements of both parity exist or not.
    bool isTwoParity = false;

    // Iterate over all elements of 'A'.
    for (int i = 1; i < n; i++) {

        /* 
           If any element of 'A' is not equal to to 'A[0]', then 'isTwoParity' will 
           be updated to true.
        */
        if (a[i] != a[0]) {
            isTwoParity = true;
            break;
        }
    }

    // If 'isTwoParity' is true, then sort the array 'A' in non decreasing order.
    if (isTwoParity == true) {
        sort(a.begin(), a.end());
    }
    
    // Return 'a' as the answer.
    return a;
    
}