 
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
	int n ,point , input = 0;
    	cin >> n;
    	while (n > 0){
            for(int i = 0 ; i <3 ;i++){
                cin>>input;
            	point = point + input;
            }
            n--;
        }
	if(point == 0){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
