<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		int n, sum=0, prod=1, m;  
		cin>>n;   
		int i = n;
		while(n>0)    
		{    
			m=n%10;    
			sum = sum + m;
			prod = prod * m;
			n=n/10;    
		}    
		// cout << sum << " " << prod << " " << i << endl;
		if((sum * prod) == i)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
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
		int n, sum=0, prod=1, m;  
		cin>>n;   
		int i = n;
		while(n>0)    
		{    
			m=n%10;    
			sum = sum + m;
			prod = prod * m;
			n=n/10;    
		}    
		// cout << sum << " " << prod << " " << i << endl;
		if((sum * prod) == i)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}