#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	double a, b, c;
	double n;
	cin >> t >> a >> b >> c;
	
	while(t--) {
		cin >> n;
		double sal = n + (n*(a/100)) + (n*(b/100)) + (n*(c/100));
		cout << fixed << setprecision(2);
		cout << sal << endl;
	}
	return 0;
}