#include<iostream>
using namespace std;

int normalMaxSum(int arr[], int n)
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

int maxCircularSubarraySum(int arr[], int n)
{
    int max_normal = normalMaxSum(arr,n);
    if(max_normal < 0)
        return 0;

    int arr_sum = 0;
    for(int i=0; i<n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalMaxSum(arr, n);
    return max(max_normal, max_circular);
}

int main()
{
    int arr[] = {5, -2, 3, 4}, n=4;
    cout<<"Maximum Circular SubArray Sum = "<<maxCircularSubarraySum(arr,n)<<endl;
}
