<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string name, separator = ""; 
	float temp;
	
	while(t--) {
		cin >> name >> temp;
		if(temp > 98.6) {
			cout << separator << name ;
			separator = ", ";
		}
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string name, separator = ""; 
	float temp;
	
	while(t--) {
		cin >> name >> temp;
		if(temp > 98.6) {
			cout << separator << name ;
			separator = ", ";
		}
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}