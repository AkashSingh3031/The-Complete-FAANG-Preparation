

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length()) return vector<int>();
        map<char,int> m;
        int f[26];
        int i = 0, j = p.length()-1;
        for(auto x: p) m[x]++;
        for(int i = 0 ; i < 26; i++) f[i] = 0;
        for(int k = 0; k < j; k++) { f[s[k]-'a']++; }
        vector<int> ans;
        while(j < s.length()){
            f[s[j++]-'a']++;
            bool fa = false;
            for(int k = 0 ; k < 26; k++){
                // cout << m[k+'a'] <<" "<< f[k]<<"\n";
                if(m[k+'a'] != f[k]) { fa = true; break; }
            }
            if(!fa) { ans.push_back(i); }
            
            f[s[i++]-'a']--;
        }
        return ans;
    }
};