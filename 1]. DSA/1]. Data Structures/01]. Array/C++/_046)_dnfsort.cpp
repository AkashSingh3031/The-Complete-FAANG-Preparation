#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

void dnfsort(int arr[],int);
void swap(int [],int,int);
void print(int [],int);


int main()
    {
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }

        dnfsort(arr,n);

        print(arr,n);
        return 0;
    }

void print(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
    }

void swap(int arr[],int x,int y)
    {
        int t;
        t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }

void dnfsort(int arr[],int n)
    {
        int mid=0,b=0,e=n-1;
        while(mid<=e)
        {
            if(arr[mid]==0)
                {
                    swap(arr,b,mid);
                    mid++;
                    b++;
                }
            
            if(arr[mid]==1)
                {
                    mid++;
                }

            if(arr[mid]==2)
                {
                    swap(arr,mid,e);
                    e--;
                }
        }
    }
