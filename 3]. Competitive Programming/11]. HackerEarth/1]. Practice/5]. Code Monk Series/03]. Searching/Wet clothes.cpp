
/* 

    Solution by Rahul Surana

    ***********************************************************


We have m completely wet clothes out under sunshine waiting to become dry. 
we are now at second t1 and it's raining. 
It's going to rain again on seconds t2 ... tn and after each rain clothes will be completely wet again. 
Cloth number i needs ai  seconds to become dry. 
We can go out and collect all dry clothes at any moment but can't do this more than g times. 
What is the maximum number of clothes we can collect until second tn? 
Note that the duration of each rain is almost zero, 
so we can ignore it. Also collecting clothes does not take any time from us.

Input format

First line of input contains three integers n,m,g (2 <= n <= 100, 1 <= m, g <= 100) respectively. 
In the second line will be n increasing numbers denoting t1...tn (0 <= ti <= 10000). 
In the Last line will have m numbers denoting a1 ... am (1 <= ai <= 10000).

Output format

In a single line print maxmimum number of clothes we can collect.

    ***********************************************************
*/

#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7,MOD=1e9+7;

int main()
{
	fast_io;
    int n,m,g;
    cin >> n >> m >> g;
    int t[n], a[m];
    FOR(i,n) cin >> t[i];
    FOR(i,m) cin >> a[i];
    
    int max_interval = -1;

    for(int i = 0; i < n-1; i++) {
        if(max_interval < t[i+1]-t[i]) max_interval = t[i+1]-t[i];
    }
    int ans=0;
    FOR(i,m) if(a[i]<= max_interval) ans++;
    cout << ans;
}