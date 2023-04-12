#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
		string a;
	   	cin >> a;
	   	int n = a.length();
	   	for(int i=0;i<n;i++)
	   	{
		   	if(a[i]>='A' && a[i]<='Z')
		   		a[i]='a'+(a[i]-'A');
		   	else if(a[i]>='a' && a[i]<='z')
			   	a[i]='A'+(a[i]-'a');
	   	}
	   	cout << a << endl;
	}
	return 0;
}