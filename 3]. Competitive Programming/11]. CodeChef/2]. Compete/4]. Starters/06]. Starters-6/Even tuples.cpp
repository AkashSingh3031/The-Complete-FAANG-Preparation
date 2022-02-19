


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array A consisting of N integers and Q queries. Each query is described by two integers L and R. 
For each query, output the number of tuples (i,j,k) such that L≤i<j<k≤R and Ai+Aj+Ak is an even number.

Input Format:

The first line contains an integer T, the number of test cases. Then the test cases follow.
The first line of each test case contains two integers N and Q.
The next line contains N integers A1,…,AN.
Then Q lines follow, each containing two integers Li and Ri.

Output Format:

For each query, output the number of tuples possible as mentioned in the problem statement.


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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

ll fact(ll n);
 
ll nCr(ll n,ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
ll fact(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;
        vector<int> ar(n+4,0),pre_e(n+4,0),pre_o(n+4,0);
        FOR(i,n) { cin >> ar[i+1]; }
        int a = 0,b = 0;
        for(int i = 1 ; i <= n; i++) { if(ar[i] % 2) a++; else b++; pre_e[i] = b; pre_o[i] = a;  }
        while(q--){
            int l,r;
            ll ans = 0;
            cin >> l>> r;
            // cout << l << " "<<r;
            if(r-l < 2) cout << ans << "\n";
            else {
                ll e = pre_e[r]-pre_e[l-1],o=pre_o[r]-pre_o[l-1];
                ans += ((o * (o-1))/2 )* e;
                ans += (e*(e-1) * (e-2))/6;
                cout << ans <<"\n";
            }
        }

    }
}
