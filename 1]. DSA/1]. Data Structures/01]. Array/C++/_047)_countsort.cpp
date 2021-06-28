#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

void countsort(int arr[],int);
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

        countsort(arr,n);

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

void countsort(int arr[],int n)
    {
        int *output = new int[n];

        int maxx = arr[0];
        for(int i=0;i<n;i++)
            {
                maxx = max(arr[i],maxx);
            }

        int *count = new int[maxx+1];
        for (int i = 0; i <= maxx; ++i) {count[i] = 0;}

        for(int i=0;i<n;i++)
            {
                count[arr[i]]++;
            }

        for(int i=1;i<=maxx;i++)
            {
                count[i]+=count[i-1];
            }

            

        for(int i=n-1;i>=0;i--)
            {
                output[--count[arr[i]]] = arr[i];
            }

        for(int i=0;i<n;i++)
            {
                arr[i] = output[i];
            }

    }
