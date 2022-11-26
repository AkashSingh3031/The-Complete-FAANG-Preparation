/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of string 's'.
*/

int stringReduction(string &s) {
    int n = s.length();

    int answer = 0;

    // Iterating over the whole string.
    for (int i = 1; i < n; i++) {

        /*
        If any character is equal to its previous character,
        we can perform operation on it.
        */
        if (s[i] == s[i - 1]) {
            answer = answer + 1;
        }
    }

    // Return 'answer' as it the maximum number of operation we can perform.
    return answer;
}