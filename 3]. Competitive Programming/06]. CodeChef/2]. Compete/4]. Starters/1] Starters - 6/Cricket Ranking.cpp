

/* 

    Solution by Rahul Surana
    
    ***********************************************************


In a season, each player has three statistics: runs, wickets, and catches. 
Given the season stats of two players A and B, denoted by R, W, and C respectively, the person who is better than the other in the most statistics is regarded as the better overall player. 
Tell who is better amongst A and B. It is known that in each statistic, the players have different values.

Input Format:

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains three integers R1, W1, C1, the stats for player A.
The second line contains three integers R2, W2, C2, the stats for player B.

Output Format:

For each test case, output in a single line "A" (without quotes) if player A is better than player B and "B" (without quotes) otherwise.



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
    while(t--) {
        int r1,w1,c1,r2,w2,c2;
        cin >> r1 >> w1 >> c1 >> r2 >> w2 >> c2;
        int a=0,b=0;
        if(r1>r2) a++; else b++;
        if(w1>w2) a++; else b++;
        if(c1>c2) a++; else b++;
        if(a>b) cout << "A\n"; else cout << "B\n";

    }
}
