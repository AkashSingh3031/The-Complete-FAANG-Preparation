

/* 

    Solution by Rahul Surana

    ***********************************************************

Monk and Square Root
Given two integers N and M, help Monk find an integer X, such that X^2 % M = N and X >= 0. 
If there are multiple values of X print smallest one. If there is no possible value of X print 1.

Note: Make sure you handle integer overflow.

Input:
First line consists of a single integer T denoting the number of test cases.
Each test case consists of a single line containing two space separated integers denoting N and M.

Output:
For each test case print the required answer.


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
#define MOD 1000000007 
using namespace std;


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        ll ans = -1;
        for(ll i = 0; i < (1e6) + 1; i++) {
            if((i*i)%m == n){
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}