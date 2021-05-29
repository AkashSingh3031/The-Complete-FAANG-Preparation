#include<iostream>
using namespace std;

int remDups(int arr[], int n)
{
    int res = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] != arr[res-1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30, 30}, n=7;
    cout<<"Before Removal Duplicates: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"Size = "<<n<<endl;

    int Res = remDups(arr, n);
    cout<<"After Removal Duplicates: ";
    for(int i=0; i<Res; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"Size = "<<Res<<endl;
}
