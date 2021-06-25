/*
You are given a tree with N nodes numbered from 1 to N. A set S of nodes is called valid if there exist two vertices u and v (possibly, u=v) such that every node in S 
lies on the simple path from u to v. Count the number of valid sets modulo 109+7. Two sets are different if one node is included in one set and not in the other. 
If there are multiple pairs (u,v) making a set valid, that set is still only counted once.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains N lines of input.
The first line contains a single integer N, the number of tree nodes.
Each of the next N−1 lines contains two space-separated integers u and v representing an edge between nodes u and v.
Output
For each test case, output in a single line the number of valid sets modulo 109+7.
Sample Input
2
4
1 2
3 1
2 4
4
1 2
2 3
2 4
Sample Output
15
13
*/

#include <bits/stdc++.h>
using namespace std;
const long unsigned int mod  = 1000000007;
typedef long long int ll;
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define ppb pop_back
#define pb push_back
#define all(s) s.begin(),s.end()

const double pi = acos(-1);
ll binpow(ll a,ll b,ll md)
{
    ll res = 1;
    while(b!=0)
    {
        if(b&1)
        res*=a,res%=md;
        a*=a,a%=md;
        b>>=1;
    }
    return res%md;
}
ll ans;
vector<vector<int>> v;
vector<ll> dp,tot;
void dfs(int cur, int par)
{
    dp[cur]=1,tot[cur]=1;
    ll sum=0,cnt=0;
    f(i,0,v[cur].size())
    {
        ll node = v[cur][i];
        if(node!=par)
        {
            dfs(node,cur);
            dp[cur]+=((2*dp[node])%mod);
            dp[cur]%=mod;
            cnt++;
            tot[cur]+=tot[node];
            tot[cur]%=mod;
            tot[cur]+=dp[node];
            tot[cur]%=mod;
            sum+=dp[node];
        }
    }
    f(i,0,v[cur].size())
    {
        int node = v[cur][i];
        if(node!=par)
        {
            tot[cur]+=(dp[node]*((sum-dp[node]+mod)%mod))%mod;
            tot[cur]%=mod;
        }
    }
}

void solve()
{
    ans = 0;
    ll n;
    cin>>n;
    v.resize(n+1);
    dp.resize(n+1);
    tot.resize(n+1);
    f(i,0,n-1)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,1);
    ll ans = tot[1]%mod;
    cout<<ans<<endl;
    dp.clear(); v.clear(); tot.clear();
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
