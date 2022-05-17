/*
Given integers N and M, find the number of ordered pairs (a,b) such that 1≤a<b≤N and ((M mod a) mod b)=((M mod b) mod a)
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains two integers N, M.
Output
For each testcase, output in a single line the answer to the problem.
Sample Input
3
3 5
3 6
3 10
Sample Output
2
3
2
*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

void solve()
{
    ll n,m,count  = 0;
    cin>>n>>m;
    vector<ll> v(n+1,1);
    for(ll i=2;i<=n;i++)
    {
        ll a = m%i;
        count+=v[a];
        for(ll j =a;j<=n;j+=i)
        {
            v[j]++; 
        } 
    }
    cout<<count<<"\n";
}

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
