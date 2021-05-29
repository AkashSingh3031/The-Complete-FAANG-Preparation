#include<iostream>
using namespace std;

int maxDiff(int arr[], int n)
{
    int res = arr[1]-arr[0], minVal = arr[0];
    for(int i=1; i<n; i++)
    {
        res = max(res, arr[i]-minVal);
        minVal = min(minVal, arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n=7;
    cout<<"Maximum Difference = "<<maxDiff(arr,n)<<endl;
}
