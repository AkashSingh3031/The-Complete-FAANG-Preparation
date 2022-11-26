/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' denotes the length of the string 'S'.
*/


int isSTString(string a) {
    // 'n' is the length of the string 'a'.
    int n = a.length();

    // Iterate over the characters of the string 'S'.
    for (int i = 0; i < n; ++i) {

        // If the current character is not 'S' and not 't'.
        if (a[i] != 'S' && a[i] != 't') {

            // Then return 0.
            return 0;
        }
    }

    // Return 1 as all the characters are 'S' or 't'.
    return 1;
}
