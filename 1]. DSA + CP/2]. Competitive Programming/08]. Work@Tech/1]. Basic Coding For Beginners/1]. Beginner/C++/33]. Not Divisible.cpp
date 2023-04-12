#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;

		for(int i = 1; i <= n; i++) {
			if((i % 3) != 0) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}