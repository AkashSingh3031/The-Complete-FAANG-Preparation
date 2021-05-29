#include<iostream>
using namespace std;

int findMajority(int arr[], int n)
{
    int res = 0, count = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[res] == arr[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            res=i;
            count = 1;
        }
    }

    count = 0;
    for(int i=0; i<n; i++)
        if(arr[res] == arr[i])
            count++;
    if(count <= n/2)
        res = -1;

    return res;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 5, 5, 5}, n=7;
    cout<<"Majority Element Index = "<<findMajority(arr, n)<<endl;
}
