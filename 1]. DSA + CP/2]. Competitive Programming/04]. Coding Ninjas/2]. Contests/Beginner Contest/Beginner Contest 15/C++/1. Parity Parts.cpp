/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the length of the string 'S'.
*/

#include <string>
using namespace std;

string greaterParitySubpart(string &s) {
    
    // Declaring a variable 'n' as the length of the string 's'.
    int n = s.size();

    // Declaring two strings for storing the even and odd subparts.
    string evenSubpart, oddSubpart;

    // Iterating over the string 's' to build 'evenSubpart' and 'oddSubpart'.
    for (int i = 0; i < n; ++i) {

        /* Concatenating the current character to 'evenSubpart' if the index is even,
        otherwise, concatenating it to 'oddSubpart'. */
        if (i % 2 == 0) {
            evenSubpart += s[i];
        }
        else {
            oddSubpart += s[i];
        }
    }

    // Returning 'evenSubpart' if it is lexicographically greater, otherwise returning 'oddSubpart'.
    if (evenSubpart > oddSubpart) {
        return evenSubpart;
    }
    else {
        return oddSubpart;
    }
}