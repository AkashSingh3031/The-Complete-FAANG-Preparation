


/* 

    Solution by Rahul Surana

    ***********************************************************

Monk's best friend Micro, who happen to be an awesome programmer, got him an integer matrix M of size n * n for his birthday.
Monk is taking coding classes from Micro. 
They have just completed array inversions and Monk was successful in writing 
a program to count the number of inversions in an array. 
Now, Micro has asked Monk to find out the number of inversion in the matrix M. 
Number of inversions, in a matrix is defined as the number of unordered pairs of cells {(i,j),(p,q)} such that M[i][j] > M[p][q] and i <= p , j <= q.
Monk is facing a little trouble with this task and since you did not got him any birthday gift, 
you need to help him with this task.


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
int ar[20][20];

int main()
{
	fast_io;
    
	int n,t;
    cin >> t;
    
	FOR(i,t){ cin >> n;
    int ans = 0;
    FOR(j,n){
		FOR(k,n) {cin >> ar[j][k];}

	}

	FOR(j,n){
		FOR(k,n){ 
			for(int x = j;x<n;x++){
				for(int y = k; y<n;y++){
					if(ar[j][k]>ar[x][y]) {
						ans++;
						// cout<<ar[j][k]<<" "<<ar[x][y]<<"\n";
					}
				}
			}
		}
	}
    
    cout << ans <<"\n";
	}
}