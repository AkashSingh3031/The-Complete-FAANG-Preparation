/*
    Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
    Approch: Tabular DP
*/
/*
    Input: 
        6 6
        ABCDGH
        AEDFHR

    Output:
        3
*/

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int x, int y, string &s1, string &s2){
    // your code here
    int i,j, dp[x+1][y+1];
    for(i=0;i<=x;i++) dp[i][0]=0;
    for(j=0;j<=y;j++) dp[0][j]=0;
    
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[x][y];
}

int main(){
    int x,y;
    cin>>x>>y;          
    string s1,s2;
    cin>>s1>>s2;        
    cout << lcs(x, y, s1, s2) << endl;
    return 0;
}


