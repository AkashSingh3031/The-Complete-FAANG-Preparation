/* 
    Time Complexity: O((N ^ 2)).
    Space Complexity: O(N ^ 2),
    where 'N' denotes the number of elements in the array 'A'.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int solve(int n, int m, vector<vector<int>> &dp) {
    int mod = 1e9 + 7;

    //If 'N' < 'M', return 0.
    if(n < m) {
        return 0;
    }

    //If 'N' == 'M', return 1.
    if(n == m) {
        return 1;
    }

    //If 'N' == 0 or 'M' == 0, return 0.
    if(n == 0 || m == 0) {
        return 0;
    }

    //If dp['N']['M'] is not equal to -1, return 0.
    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    //Return dp['N']['M'] =  solve('N - 1', 'M - 1') + solve('N' , '2 * M').
    return dp[n][m]=(solve(n - 1, m - 1, dp) + solve(n, m * 2, dp))%mod;
}
int noOfArrays(int n, int m) {
    
    //Initialise a 2D array 'dp' of '(N + 1) X (N + 1)' to store the answer for all the inputs.
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

    //Call the solve function with arguments 'N' and 'M'.
    return solve(n, m, dp);
}