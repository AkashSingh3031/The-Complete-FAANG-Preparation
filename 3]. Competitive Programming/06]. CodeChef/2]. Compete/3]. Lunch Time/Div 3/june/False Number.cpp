

/* 
    Solution by Rahul Surana
    
    ***********************************************************

One day, Chef's friend gave him a wrong number W containing N+1 digits and said that the actual number A is 
the largest possible number that can be obtained from deleting exactly one digit of W. Chef was able to find A but forgot W.

Given A, find the smallest possible number W of length N+1 without leading 0's that is consistent with the story above. 
We can show that there is always at least one such W consistent with the story.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, an integer A.

Output

For each testcase, output in a single line string representing the answer to the problem.


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
        string a;
        cin >> a;
        if(a[0] == '1')
        cout << a[0] << "0" << a.substr(1,a.size()-1)<<"\n";
        else cout << "1" << a <<"\n";

    }
}
