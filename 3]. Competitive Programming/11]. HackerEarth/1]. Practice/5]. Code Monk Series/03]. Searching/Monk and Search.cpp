
/* 

    Solution by Rahul Surana

    ***********************************************************


Monk and his friend Micro are on a quest to find the answer of Life, Universe and Everything. 
In order to complete it they need to answer Q queries on an array A having N integers. 
The queries can be of following two types:
0 x : Find the number of numbers in A which are not less than x.
1 x : Find the number of numbers in A which are greater than x.
Help them complete the quest and be back in time for the next Code Monk Challenge.

Input Format:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.
Third line consists of a single integer denoting Q.
Each of the following Q lines consists of a query of one of the given two types.

Output Format:
For each query print the required answer in new line.


    ***********************************************************
*/


#include <bits/stdc++.h>
#define ll          long long int
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
int a[100001];

int binarySearch(int f, int l, int t){
    int m = 0;
    while(f<=l){
        m = (f + l) >> 1;
        // cout << f << "f " << m <<"m " << l <<"l ";
        if(a[m] < t) f = m + 1;
        else if (a[m] > t) l = m - 1;
        else return m;
    }
    return m;
}

int main()
{
	fast_io;
    int n;
    cin >> n;
    
    FOR(i,n) cin >> a[i];
    
    // FOR(i,n) cout << a[i];
    sort(a,a+n);
    // FOR(i,n) cout << a[i];
    
    int q;
    cin >> q;
    
    FOR(i,q) {

        int ar,b;
        cin >> ar >> b;
        
        int temp = binarySearch(0,n,b);
        int ans = 0;
        // cout << temp << "t "; 
        
        if(ar == 0) {
        
            while(temp >= 0 && a[temp] >= b) temp--;
        
            ans = n - temp - 1;
            if(ans < 0) ans = 0;
        } 
        else {
        
            while(temp < n && a[temp] <= b) temp++;
        
            ans = n - temp;
        }
        
        cout << ans << "\n";
    
    }
}