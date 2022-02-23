/*
Example 1:
  Input: s = "leetcode"
  Output: 0

Example 2:
  Input: s = "loveleetcode"
  Output: 2

Example 3:
  Input: s = "aabb"
  Output: -1
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char& c : s)
            m[c]++;
        for (int i = 0; i < s.size(); i++)
            if (m[s[i]] == 1) 
              return i;
        return -1;
    }
};
