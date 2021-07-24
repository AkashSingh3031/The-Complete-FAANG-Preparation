

/* 

    Solution by Rahul Surana

    ***********************************************************

Fredo and you are talking about a movie that you have recently watched while Monk is busy teaching Number Theory. 
Sadly, Monk caught Fredo talking to you and asked him to answer his question in order to save himself from punishment. 
The question says:

Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? 
Any of the given weights can be used any number of times (including 0 number of times).

Since Fredo is not able to answer the question, he asked you to help him otherwise he will get punished.

Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.

Input Format:

The first line of input consists of an integer T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.

Output Format:
For each test case, print the answer in a separate line.


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

ll g,x,y;

void extended_gcd(ll a, ll b){
    if(b==0){
        g = a;
        x = 1;
        y = 0;
        return;
    }
    extended_gcd(b,a%b);
    int temp = x ; 
    // int y0 = x - (a/b) * y;
    x = y;
    y = temp - ((a/b) * y);
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll a,b,d;
        cin >> a >> b>> d;
        extended_gcd(a,b);
        ll m,n;
        // cout << x <<" " << y << "\n";
        m = ceil((double)-x * ((double)d/(double)b));
        n = floor((double)y * ((double)d/(double)a));
        


        // cout << m <<" " << n << "\n";
        
        if(d%g!=0) cout << 0 << "\n";
        else cout << n-m+1 <<"\n";

        // Attempt 1 :
        // int c = 0;
        // if(d%2 == 1 && a%2 == 0 && b%2 == 0) cout << c << "\n";
        // else {
        //     if(b > a){
        //         for(double i = 0; i*b <= d; i++){
        //             double k = (d - (i*b))/a;
        //         // cout << k << " "<<(int)k << "\n";
        //             if(k == (int)k) c++;
        //         }
        //     }
        //     else {
        //         for(double i = 0; i*a <= d; i++){
        //             double k = (d - (i*a))/b;
        //         // cout << k << " "<<(int)k << "\n";
        //             if(k == (int)k) c++;
        //         }
        //     }
        //     cout << c << "\n";
        // }
    }
}