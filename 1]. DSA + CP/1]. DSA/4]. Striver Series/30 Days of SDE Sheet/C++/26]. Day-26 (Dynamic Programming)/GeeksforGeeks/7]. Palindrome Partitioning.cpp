//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001];
    bool check(int begin,int end,string &s){
       while(begin<end){
           if(s[begin]!=s[end]){
               return false;
           }
           begin++;
           end--;
       }
       return true;
    }
    int recur(string &s,int i){
       if(i==s.size())return dp[i] = 0;
       if(dp[i]!=-1)return dp[i];
       int minn = 1e8;
       for(int x = i; x<s.size(); x++){
           int partition = 1e8;
           if(check(i,x,s)){
               partition = 1+recur(s,x+1);
           }
           minn = min(minn,partition);
       }
       return dp[i] = minn;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return recur(str,0)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends