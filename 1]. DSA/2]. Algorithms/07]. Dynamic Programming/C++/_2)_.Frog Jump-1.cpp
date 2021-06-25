	// There are N stones, numbered 1,2,…,N. For each i=(1≤i≤N), the height of Stone i is hi.There is a frog who is initially on Stone 1.He will repeat the following action some number of times to reach Stone 
// N.If the frog is currently on Stone i,jump to Stone i+1 or Stone i+2. Here, a cost of |hi-hj| is incurred where j is the stone to land on.Find the minimum possible total cost incurred before the frog reaches Stone 
// N.

#include<bits/stdc++.h>
using namespace std;
int min_cost(int n,int *heights, vector<int>dp){
	//there wont be any cost for the first stone
	dp[0]=0;
	//there is only one option here as the frog can jump to the second stone from only the first stone, hence the cost
	dp[1]=abs(heights[1]-heights[0]);
	//from i=2, there are two choices at every step, a frog can come to step i either from step i-1 or step i-2.
	//For eg, for i-2, frog can come from stone 0 or stone 1.
	//since we have to find the minimum cost, we are just findingthe minimum cost of the two possibilities and returning it as the answer.
	for(int i=2;i<=n-1;i++){
		int first_stone=dp[i-1]+abs(heights[i]-heights[i-1]);//dp[i-1] indicates the previous cost of that particular state. we are just including the current cost after that.
		int second_stone=dp[i-2]+abs(heights[i]-heights[i-2]);
		dp[i]=min(first_stone,second_stone);
	}
	return dp[n-1];

}
int main(){
	int n;
	cin>>n;
	int heights[n];
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	vector<int>dp(n+1,0);
	cout<<min_cost(n,heights,dp);
}
//Test Cases

//n= 6
// 30 10 60 10 60 50
//Output:40

//Test Cases

//n=4
//10 30 40 20
//Output:30

//Atcoder link:https://atcoder.jp/contests/dp/tasks/dp_a
