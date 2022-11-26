/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where 'N' is the size of the array 'X'.
*/

#include<vector>
using namespace std;

int MaxMultiples(int n, vector<int> x) {

    // Associative vector to store remainder of every element when divided by 120.
    vector<int> remainder(120,0);

    // Iterate over elements of 'X' and increase frequency of corresponding remainders.
    for(int i = 0; i < n; i++) {
        remainder[ x[i]%120 ]++;
    }

    // Integer variable 'count' to store result.
    int count = 0;

    // Iterate over remainders and update 'count'.
    for(int i = 0; i < 120; i++) {

        int temp = remainder[i];

        // For every remainder, there are 'Combinations(remainder[i],2)' pairs.
        count += (temp * (temp-1))/2;
    }

    // Return 'count' as the final result.
    return count;

}