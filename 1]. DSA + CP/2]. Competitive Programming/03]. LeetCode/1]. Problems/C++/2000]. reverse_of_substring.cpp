/*
2000. Reverse Prefix of Word

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch 
(inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). 
The resulting string will be "dcbaefd".
Return the resulting string.

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".

*/

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int ind = 0;
        for (auto c : word)
        {
            ind = word.find(ch);
            if (ind == -1)
                return word;
        }
        string str1 = "";
        string str2 = "";
        for (int i = 0; i < word.length(); i++)
        {
            if (i <= ind)
                str1 += word[i];
            else
                str2 += word[i];
        }
        int i = 0;
        int n = str1.length() - 1;
        while (i <= n)
        {
            swap(str1[i], str1[n]);
            i++;
            n--;
        }
        str1 += str2;
        cout << str1 << endl;
        cout << str2;

        return str1;
    }
};

//
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        string w = "";
        int index = word.find(ch);
        if (index == 0)
        {
            return word;
        }
        else
        {
            for (int i = index; i >= 0; i--)
            {
                w += word[i];
            }
            for (int i = index + 1; i < word.size(); i++)
            {
                w += word[i];
            }
            return w;
        }
    }
};