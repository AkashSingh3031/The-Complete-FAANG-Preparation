<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		int n, t1 = 0, t2 = 1, nextTerm = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
			if(i == 1) {
				cout << t1 << " ";
				continue;
			}
			if(i == 2) {
				cout << t2 << " ";
				continue;
			}
			nextTerm = t1 + t2;
			t1 = t2;
			t2 = nextTerm;

			cout << nextTerm << " ";
		}
		cout << endl;
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
		int n, t1 = 0, t2 = 1, nextTerm = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
			if(i == 1) {
				cout << t1 << " ";
				continue;
			}
			if(i == 2) {
				cout << t2 << " ";
				continue;
			}
			nextTerm = t1 + t2;
			t1 = t2;
			t2 = nextTerm;

			cout << nextTerm << " ";
		}
		cout << endl;
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}