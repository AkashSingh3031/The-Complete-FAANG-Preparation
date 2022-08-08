#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxOcc(int L[], int R[], int n)
{
	int arr[1000];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < n; i++)
	{
		arr[L[i]]++;
		arr[R[i] + 1]--;
	}
	int maxm = arr[0], res = 0;
	for (int i = 1; i < 1000; i++)
	{
		arr[i] += arr[i - 1];
		if (maxm < arr[i])
		{
			maxm = arr[i];
			res = i;
		}
	}
	return res;
}

int main()
{
	int L[] = {1, 2, 3}, R[] = {3, 5, 7}, n = 3;
	cout << "Maximum Occuring Element in both Array = " << maxOcc(L, R, n) << endl;
}
