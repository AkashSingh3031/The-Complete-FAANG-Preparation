#include <iostream>
#include <cmath>
using namespace std;

void lRotateOne(int arr[], int n)
{
	int temp = arr[0];
	for(int i = 1; i < n; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[n - 1] = temp;
}

int main()
{
       int arr[] = {1, 2, 3, 4, 5}, n = 5;
       cout<<"Before Left Rotation"<<endl;
       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
       cout<<endl;
       lRotateOne(arr, n);
       cout<<"After '1' Left Rotation"<<endl;
       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
}
