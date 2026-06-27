#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		// Check for overflow - factorial of numbers > 20 will overflow long long
		if(n > 20) {
			cout << "Value too large for computation" << endl;
			continue;
		}
		
		long long res=1;
		for(int i=1; i<=n; i++)
			res *= i;
		cout << res << endl;
	}
	return 0;
}