#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int total, i, temp;
	cin >> total;

	int array[total];
	for (i = 0; i < total; i++)
		cin >> array[i];

	for (i = 0; i < total; i += 2)
	{
		if (i + 1 == total)
			break;
		swap(array[i], array[i+1]);
	}
		
	for (i = 0; i < total; i++)
		cout << array[i] << " ";
	return 0;
}