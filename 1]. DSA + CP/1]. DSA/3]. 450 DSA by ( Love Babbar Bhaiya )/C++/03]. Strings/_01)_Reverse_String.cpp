//Link: https://leetcode.com/problems/reverse-string/
/*
Write a function that reverses a string. The input string is given as an array of characters s.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]*/
class Solution {
public:
    void reverseString(vector<char>& s) {
       reverse(s.begin(), s.end());  
    }
};