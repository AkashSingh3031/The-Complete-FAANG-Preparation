#include<bits/stdc++.h>
using namespace std;
int max_profit(int n,int prices[],int i,int j,int y,int dp[100][100]){
    //base case
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    //recursive case
    int op1,op2;
    op1=prices[i]*y+max_profit(n,prices,i+1,j,y+1,dp);
    op2=prices[j]*y+max_profit(n,prices,i,j-1,y+1,dp);
    int ans=max(op1,op2);
    return dp[i][j]=ans;
}
int main(){
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int dp[100][100]={0};
    cout<<max_profit(n,prices,0,n-1,1,dp);
}
