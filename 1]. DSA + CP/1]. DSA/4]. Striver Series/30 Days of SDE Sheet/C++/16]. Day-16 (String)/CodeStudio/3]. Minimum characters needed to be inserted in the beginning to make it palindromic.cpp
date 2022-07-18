#include<bits/stdc++.h>
int minCharsforPalindrome(string str) {
    // Write your code here.
    string input = str + "@";
    reverse(str.begin(),str.end());
    input += str;
    int n = input.size();
    vector<int>lps(n);
    lps[0] = 0;
    for(int i = 1 ; i < n ; ++i){
        int x = lps[i-1];
        while(input[x] != input[i]){
            if(x == 0){
                x = -1;
                break;
            }
            x = lps[x-1];
        }
        lps[i] = x + 1;
    }
    return str.size() - lps[n-1];
}