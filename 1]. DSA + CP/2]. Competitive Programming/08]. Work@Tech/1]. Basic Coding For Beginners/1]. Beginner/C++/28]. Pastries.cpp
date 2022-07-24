#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, t, n1;
	cin >> n >> t;
	
	while(t--) {
		cin >> n1;
		if(n > 0) {
			cout << "Enjoy your dessert!" << endl;
			n = n-n1;
		}
		else if(n <= 0) {
			cout << "Sorry, we are all out!" << endl;
		}
	}
	return 0;
}