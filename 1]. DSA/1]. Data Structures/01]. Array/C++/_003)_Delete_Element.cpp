#include <iostream>
#include <cmath>
using namespace std;

// Function to delete the target element from an array.
int deleteEle(int arr[], int n, int x)
{
	int i = 0;
	//Iterate over the array to get index of target element.
	for(i = 0; i < n; i++)
	{
		//compare the target value 'x' & current value arr[i] (i.e arr[0] or arr[1]
		if(arr[i] == x)
			break;
	}
	if(i == n)
		return n;
	for(int j = i; j < n - 1; j++)
	{	
		//Shifting elements backward.
		arr[j] = arr[j + 1];
	}
	//returns value of n after deletion
	return n-1;
}

int main()
{
       int arr[] = {3, 8, 12, 5, 6}, x = 12, n = 5;
       cout<<"Before Deletion"<<endl;
       for(int i=0; i < n; i++)
       {
       	cout<<arr[i]<<" ";
       }
       cout<<endl;
       n = deleteEle(arr, n, x);
       cout<<"After Deletion"<<endl;
       for(int i=0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
}
