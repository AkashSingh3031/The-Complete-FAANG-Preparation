


/* 
    Solution by Rahul Surana
    
    ***********************************************************


During a fight with the Joker, Batman's eyes lose the capability to distinguish between some pairs of colors.

Each color has an integer ID from 1 to N. There are M lists where each color belongs to exactly one list. 
Batman can distinguish colors belonging to different lists, but he cannot distinguish colors belonging to the same list.

Given a strip of L colors, find the different number of segments Batman will see as a result of his disability. 
Two positions of the strip are said to belong to the same segment if they are adjacent on the strip and Batman cannot distinguish their colors. 
See the sample explanation for clarity.

Input Format:

The first line contains an integer T, the number of test cases. Then the test cases follow.
The first line contain three integers N, M, and L - the number of colors, the number of lists, and the length of the strip, respectively.
Each of the next M lines describes a list. It begins with an integer Ki, the length of the i-th list, followed by Ki integers Ai1,Ai2,…,AiKi - the color IDs of the i-th list.
The next line contains L integers S1,S2,…,SL - the color IDs of the strip.

Output Format:

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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int arr[100001];


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,m,l;
        cin >> n >> m >> l;
        FOR(i,m) { int k; cin >> k; FOR(j,k) { int a; cin >> a; arr[a] = i; } }
        vector<int> ar(l);
        FOR(i,l) cin >> ar[i];
        int c = 0;
        for(int i = 1; i < l;i++){
            if(arr[ar[i-1]] == arr[ar[i]]) c++;
        }
        cout << l-c <<"\n";

    }
}
