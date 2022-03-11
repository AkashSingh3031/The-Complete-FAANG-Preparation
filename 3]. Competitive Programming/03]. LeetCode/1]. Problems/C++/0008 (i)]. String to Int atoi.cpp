/*
Example 1:
    Input: s = "42"
    Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
    Step 1: "42" (no characters read because there is no leading whitespace)
            ^
    Step 2: "42" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "42" ("42" is read in)
            ^
    The parsed integer is 42.
    Since 42 is in the range [-231, 231 - 1], the final result is 42.

Example 2:
    Input: s = "   -42"
    Output: -42
Explanation:
    Step 1: "   -42" (leading whitespace is read and ignored)
                ^
    Step 2: "   -42" ('-' is read, so the result should be negative)
                ^
    Step 3: "   -42" ("42" is read in)
                ^
    The parsed integer is -42.
    Since -42 is in the range [-231, 231 - 1], the final result is -42.

Example 3:
    Input: s = "4193 with words"
    Output: 4193
Explanation:
    Step 1: "4193 with words" (no characters read because there is no leading whitespace)
            ^
    Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
                ^
    The parsed integer is 4193.
    Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
*/

class Solution {
public:
    int myAtoi(string s) {
        trim(s);
        const int sign = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        long num = 0;

        for (const char c : s) {
            if (!isdigit(c))
                break;
            num = num * 10 + (c - '0');
            if (sign * num < INT_MIN)
                return INT_MIN;
            if (sign * num > INT_MAX)
                return INT_MAX;
        }
        return sign * num;
    }
private:
    void trim(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }

};