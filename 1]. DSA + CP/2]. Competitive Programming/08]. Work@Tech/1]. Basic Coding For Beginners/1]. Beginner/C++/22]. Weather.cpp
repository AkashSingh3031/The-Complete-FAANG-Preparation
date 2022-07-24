#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n1, n2;
	cin >> t;
	
	while(t--) {
		cin >> n1 >> n2;
		
		if(n1 >= 30 && n2 >= 90)
			cout << "Hot and Humid" << endl;
		else if(n1 >= 30 && n2 < 90)
			cout << "Hot" << endl;
		else if(n1 < 30 && n2 >= 90)
			cout << "Cool and Humid" << endl;
		else if(n1 < 30 && n2 < 90)
			cout << "Cool" << endl;
	}
	return 0;
}