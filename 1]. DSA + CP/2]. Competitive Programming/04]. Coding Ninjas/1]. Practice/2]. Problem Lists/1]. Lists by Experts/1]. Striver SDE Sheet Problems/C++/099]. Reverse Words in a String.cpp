#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    vector<string> words;
    stringstream ss(str);
    string tmp;
    while (ss >> tmp)
        words.push_back(tmp);

    string ans;
    for (int i = words.size() - 1; i >= 0; --i) {
        if (i != words.size() - 1) ans += " ";
        ans += words[i];
    }
    return ans;
}