#include<iostream>
using namespace std;

int getLargest(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        bool flag = true;
        for(int j=1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                flag = false;
                break;
            }
        }
        if(flag==true)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 5, 20, 8}, n=4;
    cout<<"Index = "<<getLargest(arr, n)<<endl;
}
