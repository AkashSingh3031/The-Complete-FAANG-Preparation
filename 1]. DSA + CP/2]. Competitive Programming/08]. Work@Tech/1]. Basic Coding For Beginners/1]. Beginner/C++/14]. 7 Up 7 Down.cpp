#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;
		if(n == 7)
			cout << "EQUAL" << endl;
		else if(n > 7)
			cout << "UP" << endl;
		else if(n < 7)
			cout << "DOWN" << endl; 
	}
	return 0;
}