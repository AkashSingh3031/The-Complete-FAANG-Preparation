#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int c;
    cin>>c;
    for(int i=0;i<c;i++){
        double gs=0;
        double t=0;
        cin>>gs;
        if((gs>0) && (gs<=300000.00)){
            t=0.0;
        }
        else if((gs>300000.00) && (gs<=500000.00)){
            t=t+((gs-300000.00)*(0.05));
        }
        else if((gs>500000.00) && (gs<=1000000.00)){
            t=t+(200000*(0.05));
            t=t+((gs-500000.00)*(0.2));
        }
        else{
            t=t+(200000*(0.05));
            t=t+(500000*(0.2));
            t=t+((gs-1000000.00)*(0.3));
        }
        gs=gs-t;
        cout<<fixed<<setprecision(2)<<gs<<endl; 
    }
	return 0;
}