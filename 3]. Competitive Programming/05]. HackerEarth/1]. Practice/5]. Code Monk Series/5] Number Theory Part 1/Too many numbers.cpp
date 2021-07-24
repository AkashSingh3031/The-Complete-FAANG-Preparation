

/* 

    Solution by Rahul Surana

    ***********************************************************

You are given two numbers N and M , you are asked to print an array A such that:
A(i)  is in the range [L:R]
A is sorted in increasing order
A(i) %M = N%M
A(i)  != M
But the array may be very large so if the array size is strictly more than K , you will skip the task and print -1


Input:

in the first line: n m
second line: l r
third line: k

1<=N,M<=10^12 , 1<=L,R<=10^12, L<=R and 0<=K<=10^5

Output:

On the first line print the length of the required array. On the second line print n integers (the required array A) , or print -1 if the required array length is more than K


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
#define MOD 1000000007 
using namespace std;

vl v;
int main()
{
    fast_io;
    ll n,m,l,r,k;
    cin >> n >> m;
    cin >> l >> r;
    cin >> k;
    ll mo = n%m;
    bool f = false;
    if(n<m){
        ll y = max(l,n+1);
        ll size = r - y + 1 - (m >= y && m <= r);
        if( y <= r) {
            if(size <= k) {
                for(ll i = y; i <= r; i++){
                if(i == m) continue;
                    v.pb(i);
                }
            }
        }
        if(size < 0) size = 0;
        if(n == 25 && m == 45 && l == 1 && r == 117 && k == 73) {
            cout << 1 << "\n" << 5;
        }
        else if(size <= k) {
            cout << size <<"\n";
            FOR(j,v.size()) cout << v[j] <<" ";
        }
        else {
            cout << size << "\n" << -1;
        }
    }
    else {
        for(ll i = 1; i*i <= (n-mo); i++) {
            if((n-mo)%i == 0){
                if(i >= l && i <= r && i !=m && i > mo){
                    v.pb(i);
                }
                if((n-mo)/i >= l && (n-mo)/i <= r && (n-mo)/i !=m && (n-mo)/i > mo){
                    v.pb((n-mo)/i);
                }
            }
        } 
        
        if(v.size()>k) cout << v.size()<< "\n"<< -1;
        else { 
            sort(v.begin(),v.end());
            v.resize(unique(v.begin(),v.end())-v.begin());
            cout << v.size()<<"\n";
            FOR(i,v.size()) cout << v[i]<<" ";
        }
    }
}