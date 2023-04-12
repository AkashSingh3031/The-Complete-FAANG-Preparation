#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	float f;
	cin >> t;
	
	while(t--) {
		cin >> f;
		float res = (9*f/5)+32;
		cout << fixed << setprecision(2);
		cout << res << endl;
	}
	return 0;
}