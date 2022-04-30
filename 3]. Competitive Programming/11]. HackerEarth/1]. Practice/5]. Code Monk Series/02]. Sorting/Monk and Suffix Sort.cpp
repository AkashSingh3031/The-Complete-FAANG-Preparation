
/* 

    Solution by Rahul Surana

    ***********************************************************

Monk loves to play games. On his birthday, his friend gifted him a string S. 
Monk and his friend started playing a new game called as Suffix Game. 
In Suffix Game, Monk's friend will ask him lexicographically  smallest suffix of the string S. 
Monk wants to eat the cake first so he asked you to play the game.

Input Format:
First line contains a string S (1 <= S <= 25) and an integer k (1 <= k <= S).

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
    vector<string> ar;
    string s;
    int n;
    cin >> s >> n;

    FOR(i,s.length()) ar.pb(s.substr(i,s.length()-i));
    sort(ar.begin(),ar.end());

    // for(auto a: ar) cout<< a<<" ";
    
    cout << ar[n-1];
}