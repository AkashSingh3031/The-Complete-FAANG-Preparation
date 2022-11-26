/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the length of the string 's'.
*/

int divisibleSubstrings(string &s) {

    // 'N' is the length of the string 'S'.
    int n = s.length();
    int answer = 0;

    // We are checking every substring of 'S' ending at 'i'.
    for (int i = 0; i < n; i++) {

        /*
        If the 'i'th character is either a '0' or '5', then all the substring starting at (0<='j'<=i)
        is divisible by '5' so we increase our answer by 'i'+1 as we have 'i'+1 possibility for 'j'.
        */
        if (s[i] == '0' or s[i] == '5') {
            answer += (i + 1);
        }
    }

    // Return the 'answer' here.
    return answer;
}