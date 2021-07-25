


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Chef's school semester lasts for n days. Chef's teacher gives the students some homework every day and it is compulsory to turn in the homework by the very next day. 
Chef knows that the number of minutes needed to complete the homework on the i-th day is Hi.

Chef hates homework and wants to spend the minimum amount of time possible in doing homework. Luckily, he has a few tricks up his sleeve. 
Chef can hack the school records on any given day to make it show that the assigned homework is complete. 
However to avoid suspicion, Chef will not hack the records strictly more than k days consecutively.

Can you help Chef find the minimum possible total number of minutes that Chef needs to spend on homework?

Note:

There are multiple test cases in a single file, refer to Input section for more details.
Since the input is large, it is recommended to use fast input/output methods.

Input Format:

-> The first line contains a single integer T, the number of test cases. The description of the T test cases follow.
-> The first line of each test case contains two integers n and k - the number of days in Chef's semester and 
   the maximum number of consecutive days Chef can hack the school's record system.
-> The second line of each test case contains n integers, H1,H2,…Hn, where Hi is the number of minutes Chef needs to complete the homework given on the i-th day.

Output Format:

For each test case, print a single line containing an integer, the minimum number of minutes Chef needs to spend on homework.



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

int ar[1000001];

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        FOR(i,n) { cin >> ar[i]; }
        if(k >= n) { cout << "0\n"; continue; }
        deque<int> dm;
        vector<int> dp(n+1,0);
        for(int i = 0; i< n; i++){
            if(i < k+1) dp[i] = ar[i]; 
            else{
                dp[i] = ar[i] + dp[dm.front()];
            }
            if(!dm.empty() && dm.front() < i-k ) dm.pop_front();
            while(!dm.empty() && dp[dm.back()] > dp[i]) dm.pop_back();
            dm.push_back(i);
        }
        int ans = INT_MAX;
        FOR(i,k+1) if(ans > dp[n-1-i]) ans = dp[n-1-i];
        cout << ans << "\n";
    }
}
