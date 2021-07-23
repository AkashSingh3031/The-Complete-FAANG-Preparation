
/* 

    Solution by Rahul Surana

    ***********************************************************

Monk being the monitor of the class needs to have all the information about the class students. 
He is very busy with many tasks related to the same, so he asked his friend Mishki for her help in one task. 
She will be given heights of all the students present in the class and she needs to choose 2 students having heights h1 and h2 respectively, 
such that h1 > h2 and difference between the number of students having height h1 and number of students having height h2 is maximum.

Note: The difference should be greater than 0.

As Mishki has never been a monitor of the class, help her in the same. 
If there exists such students, then print the required difference else print "1" (without quotes).

Input:
The first line will consists of one integer T, which denotes the number of test cases.
For each test case:
One line consists of a integer N, denotes the number of students in the class.
Second line contains N space separated integers, where ith integer denotes the height of the ith student in the class.

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

int main()
{
	fast_io;
    int t;
    cin >> t;
    FOR(i,t) {
        
        int n;
        cin >> n;
        
        int ar[n];
        
        FOR(j,n) cin >> ar[j];
        
        sort(ar,ar+n);
        
        int cdiff = -1;
        vector<int> ans;
        
        // FOR(j,n) cout << ar[j] << " ";
        
        int count = 0;
        for(int j=1;j<n;j++)  {
            count++;
            if(ar[j]!=ar[j-1]) ans.pb(count), count=0;
        }
        ans.pb(count+1);
            
        // FOR(j,ans.size()) cout<<ans[j]<<" "<<"\n";
    	int cmin=ans[0],cmax=ans[0];
        for(int j=1;j<ans.size();j++)  {
            if(ans[j]>cmax) cmax=ans[j];
            if(ans[j-1]<cmin) cmin = ans[j-1];
            if(cdiff < cmax-cmin) cdiff = cmax-cmin;

            // // cout<<cdiff<<" "<< k <<" "<< j <<"\n";
        }
        cout<<cdiff<<"\n";
    }
}