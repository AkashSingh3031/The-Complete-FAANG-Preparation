

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Chef aims to be the richest person in Chefland by his new restaurant franchise. Currently, his assets are worth A billion dollars and have no liabilities. 
He aims to increase his assets by X billion dollars per year.

Also, all the richest people in Chefland are not planning to grow and maintain their current worth.

To be the richest person in Chefland, he needs to be worth at least B billion dollars.
How many years will it take Chef to reach his goal if his value increases by X billion dollars each year?

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, three integers A, B, X.

Output

For each test case, output in a single line the answer to the problem.


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
    int t;
    cin >> t;
    FOR(i,t) {
        int a,b,x;
        cin >> a>>b>>x;
        cout << ceil((b-a)/x)<<"\n";
        

    }
}
