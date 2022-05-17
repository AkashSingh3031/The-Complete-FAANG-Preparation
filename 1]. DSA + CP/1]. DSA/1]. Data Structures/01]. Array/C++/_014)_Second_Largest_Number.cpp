#include<iostream>
using namespace std;

int getSecondLargest(int arr[], int n)
{
    int res = -1, largest = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] > arr[largest])
        {
            res=largest;
            largest=i;
        }
        else if(arr[i] != arr[largest])
        {
            if(res == -1 ||arr[i] > arr[res])
                res = i;
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 5, 18, 20}, n=4;
    cout<<"Index = "<<getSecondLargest(arr, n)<<endl;;
}
