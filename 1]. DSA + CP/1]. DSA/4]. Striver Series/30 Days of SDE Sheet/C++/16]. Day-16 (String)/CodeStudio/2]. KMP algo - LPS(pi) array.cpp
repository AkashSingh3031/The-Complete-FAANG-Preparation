#include<bits/stdc++.h>
vector<int> kmpProcess(string pat) {
    int n = pat.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

bool findPattern(string p, string s)
{
   // Write your code here.
   int m = p.size();
   int n = s.size();
   if (!n) {
       return 0;
   }
   vector<int> lps = kmpProcess(p);
    for (int i = 0, j = 0; i < n;) {
        if (s[i] == p[j]) { 
            i++, j++;
        }
        if (j >= m) {
            return true;
        }
        if (i < n && s[i] != p[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return false;
}