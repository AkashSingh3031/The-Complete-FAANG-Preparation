#include <iostream>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{
	if(n == 0)
		return 0;
	if(n <= -1)
		return -1;
	int res = max(maxCuts(n-a, a, b, c),
	          max(maxCuts(n-b, a, b, c),
	          maxCuts(n-c, a, b, c)));
	if(res == -1)
		return -1;
	return res + 1;
}

int main()
{
	int n = 5, a = 2, b = 1, c = 5;
	cout<<"Maximum cutting Rod: "<<maxCuts(n, a, b, c)<<endl;
	return 0;
}
