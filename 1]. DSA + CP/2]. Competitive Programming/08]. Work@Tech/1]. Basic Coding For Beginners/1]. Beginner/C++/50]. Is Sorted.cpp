#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		
		for(int i=0; i<n; i++)
			cin >> arr[i];
		if (is_sorted(arr, arr + n))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
