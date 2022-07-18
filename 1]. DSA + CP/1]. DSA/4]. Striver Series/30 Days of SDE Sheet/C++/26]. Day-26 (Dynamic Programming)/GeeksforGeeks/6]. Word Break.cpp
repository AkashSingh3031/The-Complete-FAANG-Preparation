//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.length();
        
        int dp[n+1]={0};
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            for(auto word : B){
                int l=word.length();
                if(i+l <= n && A.substr(i,l)==word){
                    dp[i]=dp[i+l];
                }
                if(dp[i]==1)
                    break;
            }
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends