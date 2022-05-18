/*
Example 1:
    Input: s = "aa", p = "a"
    Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
    Input: s = "aa", p = "a*"
    Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
    Input: s = "ab", p = ".*"
    Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> cur(n + 1, false);
        for (int i = 0; i <= m; i++) {
            bool pre = cur[0];
            cur[0] = !i;
            for (int j = 1; j <= n; j++) {
                bool temp = cur[j];
                if (p[j - 1] == '*') {
                    cur[j] = cur[j - 2] || (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};