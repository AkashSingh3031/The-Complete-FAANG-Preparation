#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		string su;
		cin >> su;
		
		transform(su.begin(), su.end(), su.begin(), ::toupper);
		cout << su << endl;
	}
	return 0;
}