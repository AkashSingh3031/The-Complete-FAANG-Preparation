#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int T;
	cin>>T;
	while(T--)
	
	{
		long long int n,k;
		cin>>n>>k;
		k=k%n;
		long long int a[n];
		for(long long int i=0;i<n;i++)
		{
			long long int data;
			cin>>a[i];
		}
		for( int i=0;i<n;i++)
		{
			cout<<a[((n-k+i)%n)]<<" ";
		}
		cout<<"\n";}
}
