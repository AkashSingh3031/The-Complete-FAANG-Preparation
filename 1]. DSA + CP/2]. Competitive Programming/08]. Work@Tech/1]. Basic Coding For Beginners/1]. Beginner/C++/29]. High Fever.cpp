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
}