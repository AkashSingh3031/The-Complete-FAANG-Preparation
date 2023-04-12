#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	if(arr[n-1] % 2 == 0)
		cout << "WON";
	else 
		cout << "LOST";
	return 0;
}