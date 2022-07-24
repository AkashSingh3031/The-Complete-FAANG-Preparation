<<<<<<< HEAD
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
=======
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
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}