//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i , int j , vector<vector<int>> &dp , int arr[]){
        if(j==i)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j] = INT_MAX;
        for(int k = i ; k< j ; k++){
            dp[i][j] = min(dp[i][j] , solve(i,k,dp,arr) + solve(k+1,j,dp,arr) + arr[i]*arr[k+1]*arr[j+1]);
        }
   return dp[i][j];
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N , vector<int>(N , -1));
        return solve(0 , N-2 , dp , arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends