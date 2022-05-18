#include <iostream>
#include <cmath>
using namespace std;

 void reverse(int arr[], int n)
{
	int low = 0, high = n - 1;
	while(low < high)
	{
              
        //using temp variable to swap value of array elements.
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
        // Increment low till { low < high }
		low++;
		// Decement high till { high > low }
		high--;
	}
}

int main()
{
       int arr[] = {10, 5, 7, 30}, n = 4;
       cout<<"Before Reverse"<<endl;
       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
       cout<<endl;
       // Reverse function called by passing whole array and size of array as parameters.
       reverse(arr, n);
       cout<<"After Reverse"<<endl;
        //Printing array after Reversing.
       for(int i = 0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
}
