#include<iostream>
using namespace std;

int maxEvenOdd(int arr[], int n)
{
    int res = 1;
    for(int i=0; i<n; i++)
    {
        int curr = 1;
        for(int j=i+1; j<n; j++)
        {
            if((arr[j]%2 == 0 && arr[j-1]%2 != 0) ||
               (arr[j]%2 != 0 && arr[j-1]%2 == 0))
                    curr++;
            else
                break;
        }
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[] = {10, 12, 14, 7, 8}, n=5;
    cout<<"Maximum Length of Even-Odd = "<<maxEvenOdd(arr, n)<<endl;
}
