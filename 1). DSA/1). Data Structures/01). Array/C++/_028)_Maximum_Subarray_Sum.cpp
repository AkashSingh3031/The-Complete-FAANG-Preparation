#include<iostream>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i=1; i<n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3}, n=7;
    cout<<"Maximum SubArray Sum = "<<maxSubarraySum(arr,n)<<endl;
}
