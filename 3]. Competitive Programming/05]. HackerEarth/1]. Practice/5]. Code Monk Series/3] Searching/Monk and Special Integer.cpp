

/* 

    Solution by Rahul Surana

    ***********************************************************

Monk and his best friend Micro were taking a stroll, when they found an array A having N integers lying on the road. The array was injured badly, so they took it with them and treated it.

When the array came back to senses, it told them, that some crazy guy came and started beating it. The array started crying and while Monk and Micro were comforting it, the last element of the array informed that the special integer is missing from its pocket. After hearing that, the array started crying even louder because it is supposed to appear in the next Code Monk Challenge with that Special Integer.

Special integer, K, of an array, is an integer such that none of its subarray of size K has sum of elements greater than X. To calm the array down, Monk decided to gift it the maximum possible value of special integer K. Now since Monk is busy with Code Monk he asked Micro to find the maximum value of special integer but right now, all Micro can think of is a Potato, so Micro asked for your help.

Input Format:
First line consists of two space separated integers denoting N and X.
Second line consists of N space separated integers denoting the array A.

Output Format:
Print the maximum possible value of special integer.

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

ll int ms(ll int ar[], int n, int k,int x) {
    ll int sl = 0;
    ll int ms = 0;
    for(int j = 0; j < k; j++) sl += ar[j];
    ms = sl;
    for(int j = k; j < n; j++){
        sl -= (ar[j-k]-ar[j]);
        if(sl>ms) ms = sl;
    }
    return ms;
}

int main()
{
	fast_io;
    ll int n,x;
    cin >> n >>x;
    
    ll int ar[n];
    FOR(i,n) { cin >> ar[i];}
    int ans = 0;
    ll int s = 0, m, e = n, i;
    ll int sum;
    while(s<=e){
        sum = 0;
        m = s + (e-s) / 2;
        for(i = 0; i < m; i++) { 
            sum += ar[i];
            if(sum > x) break; 
        }
        if(sum <= x) {
            for(i = m; i < n; i++){
                sum -= ar[i-m];
                sum += ar[i];
                if(sum > x) break;
            }
        }
        if(sum > x) e = m-1;
        else { ans = m; s = m+1; }
    }
    // bool f = false;
    // int k = 0;
    // for(int i = 1; i <= n; i++) { 
    //     ll int s = ms(ar,n,i,x);
    //     // cout << s <<" ";
    //     if(s <= x) { k = i;  continue; }
    //     f = false;
    //     break;
    // }
    cout << ans;
}