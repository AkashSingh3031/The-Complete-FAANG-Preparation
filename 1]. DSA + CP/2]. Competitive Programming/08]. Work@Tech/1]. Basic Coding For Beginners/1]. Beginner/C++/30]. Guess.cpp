#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int d, n;
	cin >> d;
	while(true) {
		cin >> n;
		if(d != n)
			cout << "Incorrect Guess" << endl;
		else if(d == n) {
			cout << "Correct Guess";
			return false;
		}
	}
	return 0;
}