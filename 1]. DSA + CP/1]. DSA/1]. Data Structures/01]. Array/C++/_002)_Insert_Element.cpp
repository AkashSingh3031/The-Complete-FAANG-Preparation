#include <iostream>
#include <cmath>
using namespace std;
//This function will insert element in array
int insert(int arr[], int n, int x, int cap, int pos)
{
	//If size of array we give as an input is equal to capacity of array so we can not insert element. 
	if(n == cap)
		return n;
	
	int idx = pos - 1;
	//We start from end and go through (pos-1)
	for(int i = n - 1; i >= idx; i--)
	{
		//We shift every element forward
		arr[i + 1] = arr[i];
	}
	//Insert x at (pos-1)
	arr[idx] = x;
	
	//return new n
	return n + 1;
}

int main()
{
       int arr[5], cap = 5, n = 3;
       arr[0] = 5; arr[1] = 10; arr[2] = 20;
       cout<<"Before Insertion"<<endl;
       for(int i=0; i < n; i++)
       {
       	cout<<arr[i]<<" ";
       }
       cout<<endl;
       int x = 7, pos = 2;
       n = insert(arr, n, x, cap, pos);
       cout<<"After Insertion"<<endl;
       for(int i=0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
}
