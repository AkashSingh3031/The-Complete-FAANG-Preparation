#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int low = 0, mid = 0, high = n-1;
    
    while(mid <= high) {
        switch(arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
        }
    }
}
