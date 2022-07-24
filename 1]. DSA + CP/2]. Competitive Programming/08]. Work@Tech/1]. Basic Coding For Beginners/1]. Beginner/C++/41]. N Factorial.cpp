#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		long long res=1;
		cin >> n;
		for(int i=1; i<=n; i++)
			res *= i;
		cout << res << endl;
	}
	return 0;
}