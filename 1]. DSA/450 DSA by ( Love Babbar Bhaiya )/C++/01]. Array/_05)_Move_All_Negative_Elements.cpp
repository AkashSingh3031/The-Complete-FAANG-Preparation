#include <iostream>
using namespace std;

void MoveNegative(int arr[], int arr_size)
{
    int j=0;
    for(int i=0; i<arr_size; i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    int arr[] = {1, -5, 7, -4, -6, -84, 44, 6}, arr_size = 8;
    MoveNegative(arr, arr_size);
    
    cout<<"All Negative Elements moved one side: ";
    for(int i=0; i<arr_size; i++)
        cout<<arr[i]<<" ";
}