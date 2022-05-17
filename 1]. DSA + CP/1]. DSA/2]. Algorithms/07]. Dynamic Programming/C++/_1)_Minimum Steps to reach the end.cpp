#include<bits/stdc++.h>
using namespace std;
int min_steps(int *a,int n,vector<int>dp,int i){
	if(i==n-1)
		return 0;
	if(i>=n)
		return INT_MAX;
	int max_jump=a[i];
	int steps=INT_MAX;
	for(int jump=1;jump<=max_jump;jump++){
		int nextcell=i+jump;
		int subproblem=min_steps(a,n,dp,nextcell);
		if(subproblem!=INT_MAX){
			steps=min(steps,subproblem+1);
		}
	}
	return dp[n]=steps;
}
int main(){
    int n;
    cin>>n;
    int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		vector<int>dp(n+1,0);
	cout<<min_steps(a,n,dp,0)<<endl;
}
