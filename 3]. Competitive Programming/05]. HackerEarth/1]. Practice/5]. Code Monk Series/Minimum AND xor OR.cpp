

/* 

    Solution by Rahul Surana

    ***********************************************************

Given an array A of N integers. Find out the minimum value of the following expression 

  ( A(i) and A(j) ) xor ( A(i) or A(j) )  for all valid i,j. where  i != j.


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
int inf=1e9+7,MOD=1e9+7;

int ar[100005];

int main()
{
	fast_io;
    int t,n,q;
    cin >> t;
    FOR(i,t){
        cin>>n;
        FOR(j,n) cin >> ar[j];
        int ans=1000000000;
        sort(ar,ar+n);
        
        for(int k = 1; k < n; k++){
            int x = ((ar[k-1])^(ar[k]));
            if(ans>x) ans = x;
        }
        

        cout << ans << "\n";

    }
    

}