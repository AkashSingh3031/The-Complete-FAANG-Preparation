

/* 

    Solution by Rahul Surana

    ***********************************************************

Monk just purchased an array A having N integers. Monk is very superstitious. 
He calls the array A Lucky if the frequency of the minimum element is odd, otherwise he considers it Unlucky. 
Help Monk in finding out if the array is Lucky or not.

Input:
First line consists of a single integer T denoting the number of test cases.
First line of each test case consists of a single integer N denoting the size of array A.
Second line of each test case consists of N space separated integers denoting the array A.

Output:
For each test case, print "Lucky" (without quotes) if frequency of minimum element is odd, 
otherwise print "Unlucky"(without quotes). Print a new line after each test case.


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

int ar[100000];

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        mem(ar,0);
        FOR(i,n) cin >> ar[i];
        sort(ar,ar+n);
        int c = 1;
        while(ar[c] == ar[0]) c++;
        if(c%2) cout << "Lucky\n";
        else cout << "Unlucky\n"; 
    }
}