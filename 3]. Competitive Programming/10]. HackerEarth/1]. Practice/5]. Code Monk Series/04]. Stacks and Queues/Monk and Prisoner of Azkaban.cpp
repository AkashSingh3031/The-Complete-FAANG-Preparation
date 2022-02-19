
/* 

    Solution by Rahul Surana
    
    ***********************************************************

Monk's wizard friend Harry Potter is excited to see his Dad fight Dementors and rescue him and his Godfather Sirius Black. Meanwhile their friend Hermoine is stuck on some silly arrays problem. Harry does not have time for all this, so he asked Monk to solve that problem for Hermoine, so that they can go.

The problem is given an array A having N integers, for each i(1 <= i <= N), find x + y, 
where x is the largest number less than i such that A[x] > A[i] and y is the smallest number greater than i such that A[y] > A[i]. 
If there is no x < i such that A[x] > A[i], then take x = -1. Similarly, if there is no y > i such that A[y] > A[i], then take y = -1.


Input Format:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.

Output Format:
Print N space separated integers, denoting x + y for each i (1 <= i <= N)

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
    int n;
    cin >> n;
    ll ar[n], x[n], y[n];
    stack<ll> st;
    FOR(i,n) cin >> ar[i];
    FOR(i,n) { 
        if(st.empty() || ar[st.top()] > ar[i]) {
        st.push(i);
        }
        else{
            while(!st.empty() && ar[st.top()] < ar[i]) { 
                y[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()) { 
        y[st.top()] = -1;
        st.pop();
    }
    for(int i = n-1; i >=0 ; i--) { 
        if(st.empty() || ar[st.top()] > ar[i]) {
        st.push(i);
        }
        else{
            while(!st.empty() && ar[st.top()] < ar[i]) { 
                x[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()) { 
        x[st.top()] = -1;
        st.pop();
    }
    FOR(i,n) cout << x[i] + y[i] << " ";
}
