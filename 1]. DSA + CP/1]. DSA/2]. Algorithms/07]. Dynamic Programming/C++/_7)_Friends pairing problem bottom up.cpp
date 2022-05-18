#include<iostream>
using namespace std;
int No_of_ways(int n){
    int dp[n+1]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(i-1)*dp[i-2]+dp[i-1];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int ans=No_of_ways(n);
    cout<<ans;
}

