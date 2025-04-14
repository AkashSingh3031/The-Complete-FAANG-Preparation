/*
'''
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
'''
*/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> map;
        set<char> set;
        int n = s.size() - 1;

        while (n >= 0)
        {
            if (map.count(s[n]) && map[s[n]] != t[n])
                return false;
            if (!map.count(s[n]) && set.count(t[n]))
                return false;

            set.insert(t[n]);
            map[s[n]] = t[n];
            n--;
        }
        return true;
    }
};