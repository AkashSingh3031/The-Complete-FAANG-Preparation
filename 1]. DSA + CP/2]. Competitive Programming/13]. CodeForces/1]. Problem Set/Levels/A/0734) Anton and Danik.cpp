#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
   int a=0,d=0;
   for(int i=0;i<n;i++){
	char ch;  
	cin>>ch;
	if(ch=='A')
		a++;
	else
	  d++;
	}
    if(a>d)
	  	cout<<"Anton"<<endl;	
    else if(a<d)
	  	cout<<"Danik"<<endl;	 
	else
	  	cout<<"Friendship"<<endl;
}
