/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the length of the string.
*/

string vowels(string s) {

    // 'count' will store the number of vowels.
    int count = 0;

    // String 't' contains all the possible vowels.
    string t = "aeiou";

    for (int i = 0; i < s.size(); i++) {

        for (int j = 0; j < t.size(); j++) {

            // If 's[i]' matches any of the string 't' characters. Then increase the count by '1'.
            if (s[i] == t[j]) {
                count++;
            }
        }
    }

    // If the 'count' is even, then we can divide the string into two parts, having an equal number of vowels.
    if (count % 2 == 0) {
        return "Yes";
    }

    return "No";
}