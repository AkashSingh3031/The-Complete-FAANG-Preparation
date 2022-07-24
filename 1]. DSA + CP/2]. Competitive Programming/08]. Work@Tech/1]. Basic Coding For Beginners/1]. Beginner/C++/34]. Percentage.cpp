#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	double s=0;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=0; i<n; i++)
		s += arr[i];
	cout << fixed << setprecision(2);
	cout << s/(0.8*n) <<"%";
	return 0;
}