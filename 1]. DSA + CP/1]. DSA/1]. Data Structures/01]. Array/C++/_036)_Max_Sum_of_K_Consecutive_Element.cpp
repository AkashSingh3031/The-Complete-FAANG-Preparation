#include<iostream>
using namespace std;

int maxSumOf_K_Element(int arr[], int k, int n)
{
    int max_sum=0;
    for(int i=0; i+k-1<n; i++)
    {
        int sum = 0;
        for(int j=0; j<k; j++)
            sum += arr[i+j];
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7}, k=3, n=6;
    cout<<"Max Sum of 3 Consecutive Element = "<<maxSumOf_K_Element(arr, k, n)<<endl;
}
