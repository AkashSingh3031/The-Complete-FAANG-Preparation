/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' denotes the length of the string 'S'.
*/

int minimumCommas(string s, int k) {

    // Length of the string 's'.
    int n = s.length();

    // Store the current number formed.
    long long cur = 0;

    // 'ans' stores the final answer.
    int ans = 0;

    // Iterate over the string.
    for (int i = 0; i < n; ++i) {

        // If we can include this digit in the current number.
        if (cur * 10 + (s[i] - '0') <= k) {

            // Include this digit in the current number.
            cur = cur * 10 + (s[i] - '0');
        }else{

            // If 'cur' is '0', it's impossible to place commas.
            if (cur == 0) {

                // Return the integer '-1'.
                return -1;
            }else{

                // Increment the answer 'ans'.
                ans++;

                // Set 'cur' to the current digit.
                cur = s[i] - '0';
            }
        }
    }

    // If 'cur' > 0, it means the last number is 'cur'.
    if (cur > 0) {

        // Increment the 'ans'.
        ans++;
    }

    // Return the number of commas which is one less than numbers formed.
    return ans - 1;
}
