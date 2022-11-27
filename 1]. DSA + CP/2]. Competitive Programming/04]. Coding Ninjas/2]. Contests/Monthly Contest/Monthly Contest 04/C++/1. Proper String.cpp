/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of the string 'S'.
*/

#include <string>
using namespace std;

bool isProper(string &s) {
    
    // Declaring 'n' as the length of the string 's'.
    int n = s.size();

    // Iterating over all the pairs of adjacent characters in the string 's'.
    for (int i = 1; i < n; ++i) {

        // Declaring 'cur' which denotes that the current character is a vowel or a consonant.
        bool cur = false;

        // Assigning 'cur' as true if the current character is a vowel.
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' 
          or s[i] == 'o' or s[i] == 'u') {
            cur = true;
        }

        // Declaring 'prev' which denotes that the previous character is a vowel or a consonant.
        bool prev = false;

        // Asigning 'prev' as true if the previous character is a vowel.
        if (s[i - 1] == 'a' or s[i - 1] == 'e' or s[i - 1] == 'i' 
          or s[i - 1] == 'o' or s[i - 1] == 'u') {
            prev = true;
        }

        /* Returning false if 'cur' is equal to 'prev' as it means that both the current
        and the previous characters are either vowels or consonants. */ 
        if (cur == prev) {
            return false;
        }
    }

    /* Returning true since there are no two adjacent characters which are both
    vowels or consonants, meaning the string is a preoper string. */
    return true;
}