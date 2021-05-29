#include<iostream>
using namespace std;

bool checkEquilibrium(int arr[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	int l_sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(l_sum == sum - arr[i])
			return true;
		l_sum += arr[i];
		sum -= arr[i];
	}
	return false;
}

int main()
{
    int arr[] = {4, 2, 2}, n = 3;
    cout<<checkEquilibrium(arr, n)? "true" : "false";
    cout<<endl;
}
