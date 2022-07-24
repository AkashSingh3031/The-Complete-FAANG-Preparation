<<<<<<< HEAD
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
=======
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
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}