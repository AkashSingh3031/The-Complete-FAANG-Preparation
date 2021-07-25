#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define endl "\n"
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define mod   1000000009
 
void io()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("/home/kashif/cp/input.txt","r",stdin);
		
		freopen("/home/kashif/cp/output.txt","w",stdout);
	#endif
 
}
int i,j,k;
int M[4][4] = {{0,99,-10,2},{1,0,0,0},{0,1,0,0},{0,0,0,10}};
int p;
void multiply(int a[4][4],int b[4][4])
{
 
	int mul[4][4]={0};	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				
				p=(a[i][k]*b[k][j]);
				mul[i][j]=(mul[i][j]+p);
			
			}
		}
	}
	
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			a[i][j]=mul[i][j]%mod;
	}
 
}
void power(int a[4][4],int n) 
{ 
    if(n==1 || n==0)
    	return;
    power(a,n/2); 
    multiply(a,a); 
    if (n%2 != 0) 
        multiply(a,M); 
}
 
int32_t main() 
{
	
	fastio();
	io();
	int t,n,ans;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		if(n==0)
			printf("%d\n",1);
		else if(n==1)
			printf("%d\n",10);
		else if(n==2)
			printf("%d\n",99);
		else if(n==3)
			printf("%d\n",980);
		else
		{
			int a[4][4]={{0,99,-10,2},{1,0,0,0},{0,1,0,0},{0,0,0,10}};
			power(a,n-3);
			p=(a[3][3]*1000);
			k=(a[0][0]*20+a[0][1]+100*a[0][3])%mod;
			ans=(p-k+mod)%mod;
			printf("%lld\n",ans);
		}	
	}	
}
