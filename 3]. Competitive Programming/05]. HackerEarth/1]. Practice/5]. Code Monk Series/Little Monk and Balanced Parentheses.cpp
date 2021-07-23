

/* 

    Solution by Rahul Surana

    ***********************************************************

Given an array of positive and negative integers, denoting different types of parentheses. 
The positive numbers xi denotes opening parentheses of type xi and negative number -xi denotes closing parentheses of type xi.

Open parentheses must be closed by the same type of parentheses. Open parentheses must be closed in the correct order, i.e., 
never close an open pair before its inner pair is closed (if it has an inner pair). Thus, [1,2,-2,-1] is balanced, while [1,2,-1,-2] is not balanced.

You have to find out the length of the longest subarray that is balanced.

Input Format:
First line contains an input N (1 <= N <= 2*10^5), denoting the number of parentheses. 
Second line contains N space separated integers. xi (-10^5 <= xi <= 10^5, xi != 0)  denoting the ith parentheses of the array.

Output Format:
Print the length of the longest subarray that is balanced.


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

int ar[200000];

int main()
{
	fast_io;
    int n;
    cin >> n;
    mem(ar,0);
    FOR(i,n) cin >> ar[i];
    stack<int> st;
    int c = 0,mx = 0;
    int bc = 0;
    FOR(i,n) {
        if(ar[i] > 0) { st.push(i); }
        else {
            if(!st.empty() && ar[i] == -ar[st.top()]) { 
                st.pop();  
                int x;
                if(st.empty()) x = -1;
                else x = st.top();
                
                c = i-x;
                if(c > mx) mx = c;
            }
            else {  
                st.push(i);
            }
        }
    }
    cout << mx;
}