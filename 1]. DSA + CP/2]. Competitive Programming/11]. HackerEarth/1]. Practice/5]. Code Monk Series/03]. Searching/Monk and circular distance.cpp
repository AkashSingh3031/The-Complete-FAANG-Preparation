

/* 

    Solution by Rahul Surana

    ***********************************************************

Its time for yet another challenge, 
and this time it has been prepared by none other than Monk himself for Super-Hardworking Programmers like you.
So, this is how it goes:

Given N points located on the co-ordinate plane, 
where the ith point is located at co-ordinate (xi, yi) , you need to answer q queries.

In the ith query, you shall be given an integer ri, 
and considering you draw a circle centered at the origin (0, 0) with radius ri, 
you need to report the number of points lying inside or on the circumference of this circle.

For each query, you need to print the answer on a new line.

Input Format :

The first line contains a single integer N denoting the number of points lying on the co-ordinate plane. 
Each of the next N lines contains 2 space separated integers xi and yi, 
denoting the x and y co-ordintaes of the ith point.

The next line contains a single integer q, denoting the number of queries. 
Each of the next q lines contains a single integer, 
where the integer on the ith line denotes the parameters of the ith query ri.

Output Format :

For each query, print the answer on a new line.

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

int main()
{
	fast_io;
    ll n, x, y, q, r;
    vector<ll> radii;
    cin >> n;
    FOR(i,n) cin >> x >> y, 
            radii.pb((x*x)+(y*y));

    sort(radii.begin(),radii.end());
    // FOR(i,n) cout << sqrt(radii[i]) <<" ";
    cin >> q;
    FOR(i,q) { 
        cin >> r;
        ll s = 0, m, e = n;
        while (s<e) {
            m = (s + e) >> 1;
            if(r < sqrt(radii[m])) e = m;
            else s = m+1;
            // else break;
            // cout << ans <<" ";
        }
        if(s < n) cout << s << "\n";
        else cout << n << "\n";
    } 
    
}
