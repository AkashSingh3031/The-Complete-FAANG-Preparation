/*
    Time Complexity: O(N * M)
    Space Complexity: O(N)

    where 'N' is the number of toys,
    and 'M' is the number of offers.
*/

#include <vector>
using namespace std;

long long minimumPrice(vector<int> &p, vector<int> &x, vector<int> &y) {
    
    // Declaring variables 'n' as the number of toys, and 'm' as the number of offers.
    int n = p.size(), m = x.size();

    // Declaring a variable 'priceSum' and storing the sum of the toys' prices.
    long long priceSum = 0;
    for (int i = 0; i < n; ++i) {
        priceSum += p[i];
    }

    // Creating a one-dimensional array 'dp' with dimension 'n + 1' and initializing it with 0.
    vector<long long> dp(n + 1, 0);

    // Running a loop for iterating over the number of offers available to be used.
    for (int i = 1; i <= m; ++i) {

        // Running a nested loop for iterating over the number of toys to be bought.
        for (int j = n; j > 0; --j) {

            // Updating 'dp[j]' if it is possible to buy the first 'j' toys after using the 'i - 1'th offer.
            if (x[i - 1] <= j) {
                dp[j] = max(dp[j], (long long)y[i - 1] + dp[j - x[i - 1]]);
            }
        }
    }

    // Returning the final answer 'priceSum - dp[N]' as the maximum possible discount will be stored in 'dp[N]'.
    return (priceSum - dp[n]);
}