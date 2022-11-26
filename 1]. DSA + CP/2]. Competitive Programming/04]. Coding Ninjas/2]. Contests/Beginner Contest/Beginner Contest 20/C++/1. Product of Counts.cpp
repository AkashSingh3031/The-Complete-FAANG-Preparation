/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the length of the string.
*/

int productOfCounts(int n, string &s) {
    int mod = 1e9 + 7;

    // Initialise the answer variable.
    long long ans = 1;

    // Iterate through all lowercase english letters.
    for (char c = 'a'; c <= 'z'; c++) {
        // Count the number of occurrences of the current letter.
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += s[i] == c;
        }

        // If the count of the current letter is at least 1, Multiply the count into the answer.
        if (cnt >= 1) {
            ans = (ans * cnt) % mod;
        }
    }

    // Return the final answer.
    return (int)ans;
}
