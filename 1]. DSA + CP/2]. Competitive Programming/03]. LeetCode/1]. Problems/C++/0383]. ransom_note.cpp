/*
'''
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
'''
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> dic;

        for (auto c : magazine)
        {
            if (dic.find(c) == dic.end())
                dic[c] = 1;
            else
                dic[c]++;
        }

        for (char c : ransomNote)
        {
            if (dic.find(c) != dic.end() && dic[c] > 0)
                dic[c]--;
            else
                return false;
        }

        return true;
    }
};

//
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        sort(begin(ransomNote), end(ransomNote));
        sort(begin(magazine), end(magazine));

        int i = 0, j = 0;

        while (i < ransomNote.length() && j < magazine.size())
        {
            if (ransomNote[i] == magazine[j])
            {
                i++;
                j++;
            }
            else if (ransomNote[i] > magazine[j])
                j++;
            else
                return false;
        }

        return i == ransomNote.size();
    }
};

//best
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        valarray<int> count(0, 26);
        for (char c : ransomNote)
        {
            count[c - 'a']++;
        }
        for (char c : magazine)
        {
            count[c - 'a']--;
        }
        return count.max() <= 0;
    }
};