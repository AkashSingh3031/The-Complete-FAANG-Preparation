#include <iostream>
using namespace std;

void bonacciseries(long n, int m)
{
	cout << "N-bonacci Numbers = ";
	int a[m] = {0};
	a[n - 1] = 1;
	a[n] = 1;
	for (int i = n + 1; i < m; i++)
		a[i] = 2 * a[i - 1] - a[i - n - 1];
	for (int i = 0; i < m; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int N = 5, M = 15;
	bonacciseries(N, M);
	return 0;
}
