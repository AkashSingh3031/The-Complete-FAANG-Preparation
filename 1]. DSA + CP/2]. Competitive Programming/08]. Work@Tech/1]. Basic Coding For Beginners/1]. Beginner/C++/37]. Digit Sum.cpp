<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		int n,sum=0,m;  
		cin>>n;    
		while(n>0)    
		{    
			m=n%10;    
			sum=sum+m;    
			n=n/10;    
		}    
		cout << sum << endl;  
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		int n,sum=0,m;  
		cin>>n;    
		while(n>0)    
		{    
			m=n%10;    
			sum=sum+m;    
			n=n/10;    
		}    
		cout << sum << endl;  
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}