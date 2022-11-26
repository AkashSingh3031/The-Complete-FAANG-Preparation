/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of the array 'A'.
*/

#include <string>
#include <vector>

using namespace std;

string parityBalance(vector<int> &a) {

    // Declaring 'n' as the length of the array 'a'.
    int n = a.size();

    /* Declaring 'even_sum' and 'odd_sum' with initial value 0 
    as 64-bit integers as the final value may exceed 32-bit integer limit. */
    long long even_sum = 0, odd_sum = 0;

    // Iterating through the array 'a' to calculate 'even_sum' and 'odd_sum'.
    for (int i = 0; i < n; ++i) {

        /* Adding 'a[i] * a[i]' to 'even_sum' if the index 'i' is even;
        otherwise the index 'i' is odd, so we add 'a[i] * a[i]' to 'odd_sum'. */
        if (i % 2 == 0) {
            even_sum += ((long long) a[i] * a[i]);
        } 
        else {
            odd_sum += ((long long) a[i] * a[i]);
        }
    }

    /* Comparing 'even_sum' and 'odd_sum', 
    then returning "EVEN" if the array 'a' is even-heavy, 
    returning "ODD" if it is odd-heavy, 
    and returning "BALANCED" if it is balanced. */
    if (even_sum > odd_sum) {
        return "EVEN";
    } 
    else if (odd_sum > even_sum) {
        return "ODD";
    } 
    else {
        return "BALANCED";
    }
}