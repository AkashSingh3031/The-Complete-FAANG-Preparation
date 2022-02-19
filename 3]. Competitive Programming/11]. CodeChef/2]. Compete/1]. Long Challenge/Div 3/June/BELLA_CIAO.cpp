#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll D,d,P,Q,i,j,n,rem;
	    cin>>D>>d>>P>>Q;
	    n = D/d;
	    if(D%d==0)
	    {
    	    j = d*n*P ;
    	    j += Q*(n-1)*n*d/2;
    	    cout<<j<<"\n";
	    }
	    else
	    {
	        j = d*n*P ;
    	    j += Q*(n-1)*n*d/2;
    	    rem = D%d;
    	    j+=rem*(P + n*Q);
	        cout<<j<<"\n";
	    }
	}
	return 0;
}
