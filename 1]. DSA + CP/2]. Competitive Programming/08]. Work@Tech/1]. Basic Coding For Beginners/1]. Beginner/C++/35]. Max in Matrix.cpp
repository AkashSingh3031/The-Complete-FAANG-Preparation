<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int m,n,i,j,high,low;
	cin>>m>>n;
	int a[m][n];
	
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			cin>>a[i][j];

	high=a[0][0];
	low=a[0][0];
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j]>high)
				high=a[i][j];
			else if(a[i][j]<low)
				low=a[i][j];
		}
	}
	cout << high;
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int m,n,i,j,high,low;
	cin>>m>>n;
	int a[m][n];
	
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			cin>>a[i][j];

	high=a[0][0];
	low=a[0][0];
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j]>high)
				high=a[i][j];
			else if(a[i][j]<low)
				low=a[i][j];
		}
	}
	cout << high;
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}