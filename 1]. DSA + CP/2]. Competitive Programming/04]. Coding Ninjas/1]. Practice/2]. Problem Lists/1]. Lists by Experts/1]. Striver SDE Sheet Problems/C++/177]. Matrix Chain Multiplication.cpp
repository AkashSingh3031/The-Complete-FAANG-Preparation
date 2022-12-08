#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int solve(vector<int>& arr,int i,int j)
{
    if(i+1==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    int mn = INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        int temp = solve(arr,i,k) + solve(arr,k,j) + (arr[i]* arr[k]*arr[j]);
        if(temp<mn)
        {
            mn = temp;
        }
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    if(n<=1)return 0;
    memset(dp,-1,sizeof(dp));
    return solve(arr,0,n-1);
}