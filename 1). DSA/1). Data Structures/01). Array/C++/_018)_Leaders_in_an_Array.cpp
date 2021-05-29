#include<iostream>
using namespace std;

int leaders(int arr[], int n)
{
    int cur_leader = arr[n-1];
    cout<<cur_leader<<" ";

    for(int i=n-2; i>=0; i--)
    {
        if(cur_leader < arr[i])
        {
            cur_leader = arr[i];
            cout<<cur_leader<<" ";
        }
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 6, 5, 2}, n=7;
    cout<<"Leasers in Reverse Order = ";
    leaders(arr, n);
    cout<<endl;
}
