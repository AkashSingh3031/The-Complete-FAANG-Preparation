<<<<<<< HEAD
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
=======
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
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}