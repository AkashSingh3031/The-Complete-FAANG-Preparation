<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int arr[3];
	while(t--) {
		for(int i=0; i<3; i++)
			cin >> arr[i];
		sort(arr, arr+3);
		if(arr[0] + arr[1] >= arr[2])
			cout << (arr[0]+arr[1]+arr[2]) << endl;
		else if(arr[0] + arr[1] < arr[2])
			cout << -1 << endl;
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int arr[3];
	while(t--) {
		for(int i=0; i<3; i++)
			cin >> arr[i];
		sort(arr, arr+3);
		if(arr[0] + arr[1] >= arr[2])
			cout << (arr[0]+arr[1]+arr[2]) << endl;
		else if(arr[0] + arr[1] < arr[2])
			cout << -1 << endl;
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}