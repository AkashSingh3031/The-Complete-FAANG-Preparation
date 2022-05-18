#include<iostream>
using namespace std;

void moveToEnd(int arr[], int n)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            count++;
        }
    }
}

int main()
{
    int arr[] = {0, 8, 5, 0, 0, 10, 0, 20}, n=8;
    cout<<"Before Move Zeros: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"Size = "<<n<<endl;

    moveToEnd(arr, n);
    cout<<"After Move Zeros: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"Size = "<<n<<endl;
}
