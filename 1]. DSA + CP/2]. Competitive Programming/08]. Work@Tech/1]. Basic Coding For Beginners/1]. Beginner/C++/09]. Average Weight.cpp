#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	double sum=0;
	double arr[10];
	for(int i=0; i<10; i++)
		cin >> arr[i];
	
	for(int i=0; i<10; i++)
		sum += arr[i]; 
	
	double res = sum/10;
    cout << fixed << setprecision(6);
	cout << res;
}