#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[1000];
	int n;
	int p, q;
	cin >>n>>p;
	int cnt = 0;
	for(int i=0;i<p;i++){
		cin >> arr[i];
	}
	cin>> q;
	for(int i = p; i< p+q; i++){
		cin >> arr[i];
	}
	sort(arr ,arr + (p+q));
	for(int i=0; i < p+q; i++){
		if(arr[i]!=arr[i+1])
			cnt++;
		
	}
   if(n==cnt)
   	cout<<"I become the guy."<<endl;
   
   else
   	cout<<"Oh, my keyboard!"<<endl;
	}
