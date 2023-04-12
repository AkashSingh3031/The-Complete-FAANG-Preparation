#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i]%2 == 0)
			cout << "EVEN" << endl;
		else 
			cout << "ODD" << endl;
	}
	return 0;
}