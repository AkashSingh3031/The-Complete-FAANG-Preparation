#include<iostream>
using namespace std;

int findMajority(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int count = 1;
        for(int j=i+1; j<n; j++)
            if(arr[i] == arr[j])
                count++;
        if(count > n/2)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 5, 5, 5}, n=7;
    cout<<"Majority Element Index = "<<findMajority(arr, n)<<endl;
}
