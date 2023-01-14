#include <iostream>
using namespace std;
int binarySearch (int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
	{
	    return mid;
	}
        if (key > arr[mid])
	{
	    s = mid + 1;
	}
        else
	{
	    e = mid - 1;
	}
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main ()
{
    int arr[] = { 1, 2, 4, 5, 7, 9, 11 };
    int n = 7;
    int ans = binarySearch (arr, 7, 2);
    if (ans == -1)
        cout << "Not Found ";
    else
        cout << " Element found at index " << ans;
}
