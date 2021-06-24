#include<iostream>
using namespace std;
int ladder_problem_Bottom_up_optimised(int n,int k){
    int dp[n+1]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=2*dp[i-1];
    }
    for(int i=2;i<=n;i++){
        if(i-(k+1)>=0)
            dp[i]=2*dp[i-1] - dp[i-(k+1)];
    }
    return dp[n];
}
int main(){
    int n,k;
    cin>>n>>k;
    int ans=ladder_problem_Bottom_up_optimised(n,k);
    cout<<ans;
}
