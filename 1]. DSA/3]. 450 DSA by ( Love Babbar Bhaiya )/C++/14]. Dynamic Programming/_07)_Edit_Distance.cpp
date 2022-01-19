/*
   GFG problem link:-  https://practice.geeksforgeeks.org/problems/edit-distance3702/1
   Approach:- Recursive + memoization 
*/

/*
    Input: 
        geek gesek

    Output:
        1
*/

#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
int solve(string &s, string &t, int is, int it){
   if(is==s.size()) return t.size()-it;
   if(it==t.size()) return s.size()-is;
   if(dp[is][it]!=-1) return dp[is][it];
  
   if(s[is] != t[it]){
       int insert = solve(s,t,is,it+1);
       int removed = solve(s,t,is+1,it);
       int replace = solve(s,t,is+1,it+1);
       return dp[is][it] = 1+min({insert,removed,replace});
   }else return dp[is][it] = solve(s,t,is+1,it+1);
}
int editDistance(string &s, string &t) {
    // Code here
    memset(dp,-1,sizeof(dp));
    return solve(s,t,0,0);
}


int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t)<<endl;
    return 0;
}