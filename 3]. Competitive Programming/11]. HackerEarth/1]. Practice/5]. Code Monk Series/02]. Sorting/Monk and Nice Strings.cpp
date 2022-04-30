
/* 

    Solution by Rahul Surana

    ***********************************************************

Monk's best friend Micro's birthday is coming up. 
Micro likes Nice Strings very much, so Monk decided to gift him one. 
Monk is having N nice strings, so he'll choose one from those. 
But before he selects one, he need to know the Niceness value of all of those. 
Strings are arranged in an array A, 
and the Niceness value of string at position i is defined as the number of strings having position less than i 
which are lexicographicaly smaller than A(i). 
Since nowadays, Monk is very busy with the Code Monk Series, he asked for your help.
Note: Array's index starts from 1.

Input:
First line consists of a single integer denoting N.
N lines follow each containing a string made of lower case English alphabets.

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

vector<string> arr; 

int main()
{
	fast_io;
    int n;
    cin >> n;
    FOR(i,n) {
        string a; 
        cin >> a; 
        arr.pb(a);
    }
    cout << 0 << "\n";
    for(int i = 1;i<n;i++){
        int ans=0;
        for(int j = 0; j<i;j++){
            if(arr[j]<arr[i]) ans++;
        }
        cout<<ans<<"\n";
    }
}