

/* 

    Solution by Rahul Surana

    ***********************************************************

Monk is fond of matrices. Today, he created a matrix A of size N * M. He defines four types of operations on the matrix as follows:

    -> Add v1 to all elements of a row.

    -> Update the value of all elements of a row to v2, i.e., all elements of that row become equal to v2.

    -> Add v3 to all elements of a column.

    -> Update the value of all elements of a column to v4, i.e., all elements of that column become equal to v4.

He defines a function F(x) as

    -->  F(x) = sum( sum( abs( A[i][j]))) i is from 1 to n and j is from 1 to m.

where A[i][j] refers to the jth cell in the ith row of matrix A, and abs(x) refers to absolute value of any integer x.

Now, he has defined some restrictions:

On any cell of the matrix, at most one operation can be performed. This operation can be of any type.

Any type of operation can be used any number of times.

You need to maximize the value of F(x) following these restrictions.

Input Format:

The first line consists of two integers N and M, denoting the number of rows and number of columns in matrix A respectively.

Each of the following N lines consist of M space-separated integers, where the jth integer in the ith line denotes A[i][j].

The last line of input consists of four space-separated integers denoting the values of v1,v2,v3 and v4 respectively.

Output Format:

The only line of output should consist of the maximum value of F(x)


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

int main()
{
	fast_io;
    int n,m;
    cin >> n >> m;
    ll ar[n][m];
    ll col[m][2],row[n][2];
    mem(col,0);
    mem(row,0);
    FOR(i,n) FOR(j,m) cin >> ar[i][j];
    ll v1,v2,v3,v4;
    cin >> v1 >> v2 >> v3 >> v4;
    ll rsum = 0, csum = 0;
    FOR(i,n) {
        FOR(j,m) {
            
            col[j][0] += abs(ar[i][j]);
            row[i][0] += abs(ar[i][j]);
            col[j][1] += abs(ar[i][j]+v3);
            row[i][1] += abs(ar[i][j]+v1);
        }
        rsum += max(abs(v2)*m,max(row[i][0],row[i][1]));
    }
    FOR(i,m) csum += max(abs(v4)*n,max(col[i][0],col[i][1]));
    if(rsum > csum) cout << rsum;
    else cout << csum;
}