#include<bits/stdc++.h>
using namespace std;
int count_subsequences(string a,string b, int m, int n){
    //Base Case
    //1. we have found some subsequence
    if((m==-1&&n==-1)||n==-1)
        return 1;
    //2. Source string empty
    if(m==-1)
        return 0;
    //Recursive 
    if(a[m]==b[n]){
        return count_subsequences(a,b,m,n-1)+count_subsequences(a,b,m-1,n);
    }
    return count_subsequences(a,b,m-1,n);
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<count_subsequences(a,b,a.size()-1,b.size()-1);
}
