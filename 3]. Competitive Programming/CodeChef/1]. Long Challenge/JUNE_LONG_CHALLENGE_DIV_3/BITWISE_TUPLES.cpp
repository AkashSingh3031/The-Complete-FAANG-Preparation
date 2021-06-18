#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll binpow(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
 
int main()
{
	
	
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,k;
	    cin>>n>>k;
	    ll x = binpow(2,n)-1;
	    cout<<binpow(x,k)<<endl;
	}
	
}