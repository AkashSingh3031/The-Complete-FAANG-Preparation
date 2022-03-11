/*
Example 1:
    Input: s = "abcabcbb"
    Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
    Input: s = "bbbbb"
    Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
    Input: s = "pwwkew"
    Output: 3
Explanation: The answer is "wke", with the length of 3.
            Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dict(256, -1);
        int maxlen = 0, start = 0, n = s.size();
        
        for(int i=0; i<n; i++)
        {
            if(dict[s[i]] != -1)
                start = max(start, dict[s[i]]+1);
            dict[s[i]] = i;
            maxlen = max(maxlen, i-start+1);
        }
        return maxlen;
    }
};