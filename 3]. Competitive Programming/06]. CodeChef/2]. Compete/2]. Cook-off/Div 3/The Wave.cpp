

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef is stuck in the wavey world of polynomials. You are given all N roots of a polynomial P(x)=∏Ni=1(x−ai). 
The roots are pairwise distinct integers, but they are not given in any particular order.

To help Chef escape, you should answer Q queries (numbered 1 through Q). For each valid i, in the i-th query, 
you are given an integer xi and you have to determine whether P(xi) is positive, negative or 0.

Input

-> The first line of the input contains two space-separated integers N and Q.
-> The second line contains N space-separated integers a1,a2,…,aN.
-> Q lines follow. For each valid i, the i-th of these lines contains a single integer xi describing the i-th query.

Output

For each query, print a single line containing the string "POSITIVE", "NEGATIVE" or "0" (without quotes) describing the value of the polynomial for the i-th query.


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


int ar[1000001];
bool v[1000001];

int binarySearch(int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (ar[mid] == x)
            return -1;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (ar[mid] > x)
            return binarySearch(l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return l;
}

int main()
{
    fast_io;
    
    // int t;
    // cin >> t;
    
    // while(t--) {

    ll n,q; 
    cin >> n >> q ; 
    FOR(i,n) cin >> ar[i];
    sort(ar,ar+n);
    FOR(j,q) {
        int a,count = 0;
        cin >> a;
        int ind = binarySearch(0,n-1,a);
        if(ind == -1) cout << "0\n";
        else {
            if((n-ind)%2) cout << "NEGATIVE\n";
            else cout << "POSITIVE\n";
        }        
    }
}