/*
'''
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
'''
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
};


//
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
            return true;
        vector<int> v;
        for (auto ch : s)
        {
            if (isalnum(ch))
            {
                v.push_back(tolower(ch));
            }
        }
        int begin = 0;
        int end = v.size() - 1;
        while (begin < end)
        {
            if (v[begin] != v[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};