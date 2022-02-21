


/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are three people, and each of them has an unbiased 6-sided die. The result of rolling a die will be a number between 1 and 6 (inclusive) with equal probability.

The three people throw their dice simultaneously. In this game, the third person wins only if his number is strictly greater than the sum of the other two numbers. 
Given that the first person rolls the value X and the second person rolls the value Y, what is the probability the third person will win?

Input Format:

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two integers X and Y.

Output Format:

For each test case, output the probability that the third person wins.
Your answer will be considered correct if its absolute error doesn't exceed 10−6.



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


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        double x=0,y=0;
        cin >> x >> y;
        double c = x+y;
        if(c>5) cout << 0 <<"\n";
        else cout << (double)((6-x-y)/6) <<"\n";

    }
}
