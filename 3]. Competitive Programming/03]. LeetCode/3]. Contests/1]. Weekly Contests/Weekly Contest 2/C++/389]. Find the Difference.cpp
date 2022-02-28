/*
Example 1:
  Input: s = "abcd", t = "abcde"
  Output: "e"
Explanation: 'e' is the letter that was added.

Example 2:
  Input: s = "", t = "y"
  Output: "y"
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int f[2][26] = { 0 };
        for(int i = 0 ; i < s.length(); i++)
            f[0][s[i]-'a']++;
        
        for(int i = 0 ; i < t.length(); i++)
            f[1][t[i]-'a']++;
        
        for(int i = 0; i < 26; i++) 
            if(f[0][i] != f[1][i]) 
                return i+'a';
        return '-';
    }
};
