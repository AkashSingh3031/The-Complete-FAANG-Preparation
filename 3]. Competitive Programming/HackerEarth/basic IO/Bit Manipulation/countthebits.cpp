#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,c=0;
		cin>>n;
		while(n){
          c+=n&1;
		  n=n>>1;
		}
		cout<<c<<"\n";
	}
}
