#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(n==0) return "";
        
    string ans  = "";
    sort(arr.begin(), arr.end());
    string a = arr[0];
    string b = arr[n-1];

    for(int i=0; i<a.size(); i++){
        if(a[i]==b[i]){
            ans = ans + a[i];
        }
        else{
            break;
        }
    }

    return ans;
}


