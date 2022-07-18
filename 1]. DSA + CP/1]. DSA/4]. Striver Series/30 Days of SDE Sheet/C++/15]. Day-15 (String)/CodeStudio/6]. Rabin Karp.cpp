#include<bits/stdc++.h>
vector<int> stringMatch(string &str, string &pat) {
    int n=str.length();
    int m=pat.length();
    vector<int> ans;
    int hashP=0;
    int hashT=0;
    for(int i=0;i<m;i++){
        hashP+=((pat[i]-'A'+1)*pow(5,i));
        hashT+=((str[i]-'A'+1)*pow(5,i));
    }

    int flag=0;
    if(hashP==hashT){
        bool isEqual=true;
        for(int i=0;i<m;i++){
            if(pat[i]!=str[i]){
                isEqual=false;
                break;
            }
        }
        if(isEqual){
            ans.push_back(0);
        }
    }
    
    flag=0;
    for(int i=m;i<n;i++){
        hashT=((hashT-(str[i-m]-'A'+1))/5)+((str[i]-'A'+1)*pow(5,m-1));
        if(hashT==hashP){
            bool isEqual=true;
            for(int j=0;j<m;j++){
                if(pat[j]!=str[i-m+1+j]){
                    isEqual=false;
                    break;
                }
            }
            if(isEqual){
                ans.push_back(i-m+1);
            }
        }
    }
    return ans;
}