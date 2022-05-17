#include <iostream>
using namespace std;

int main()
{
	int price[] = { 2, 30, 15, 10, 8, 25, 80 };
	int n = 7;
	int profit = 0;

	for (int i = 1; i < n; i++)
	{
		int sub = price[i] - price[i - 1];
		if (sub > 0)
			profit += sub;
	}

	cout << "Maximum Profit=" << profit;
	return 0;
}

