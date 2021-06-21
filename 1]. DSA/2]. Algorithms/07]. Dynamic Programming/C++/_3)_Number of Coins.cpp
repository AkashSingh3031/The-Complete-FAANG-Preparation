#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[V+1]={0};
        for(int i=1;i<=V;i++){
            dp[i]=INT_MAX;
            for(int j=0;j<M;j++){
                if(i-coins[j]>=0 and dp[i-coins[j]]!=-1){
                    int subproblem=dp[i-coins[j]];
                    dp[i]=min(dp[i],subproblem+1);
                }
            }
            if(dp[i]==INT_MAX)
                dp[i]=-1;
        }
        return dp[V];
	}
int main(){
    int types_of_coins;
    cin>>types_of_coins;
    int coins[types_of_coins];
    for(int i=0;i<types_of_coins;i++){
        cin>>coins[i];
    }
    int V; //amount
    cin>>V;
    cout<<minCoins(coins,types_of_coins,V);
}
