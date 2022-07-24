#include <bits/stdc++.h>
using namespace std;

void rvereseArray(int arr[], int n)
{
    int l=0, h=n-1;
  
	  while(l < h) {
		  swap(arr[l++], arr[h--]);
	  }
} 
int main() {
	// your code goes here
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	rvereseArray(arr, n);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}