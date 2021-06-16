#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int D,d,p,q,count=0,x;
		cin>>D>>d>>p>>q;
        x=D/d;
        if(x%2==0){
        	count+= (d*((x/2)*(2*p+(x-1)*q)));
        }
        else{
        	count+= (d*(x*(p+((x-1)/2)*q)));
        }
        count+=(D%d)*(p+(x)*q);
        cout<<count<<endl;
	}
	return 0;
}

