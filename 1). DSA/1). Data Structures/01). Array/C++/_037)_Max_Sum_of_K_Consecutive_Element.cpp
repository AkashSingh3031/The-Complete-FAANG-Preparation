#include<iostream>
using namespace std;

int maxSumOf_K_Element(int arr[], int k, int n)
{
    int curr_sum = 0;
    for(int i=0; i<k; i++)
        curr_sum += arr[i];
    int max_sum = curr_sum;
    for(int i=k; i<n; i++)
    {
        curr_sum += (arr[i] - arr[i-k]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7}, k=3, n=6;
    cout<<"Max Sum of 3 Consecutive Element = "<<maxSumOf_K_Element(arr, k, n)<<endl;
}
