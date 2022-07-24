#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;
		for(int i=1; i<=10; i++)
			cout << i*n << " ";
		cout << endl;
	}
	return 0;
}