#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    // Write your code here.
    int majority=0, count=0;
    
    for(int i=0; i<n; i++) {
        if(count == 0)
            majority = arr[i];
        if(majority == arr[i])
            count++;
        else
            count--;
    }
    count = 0;
    for(int i=0; i<n; i++)
        if(majority == arr[i])
            count++;
    if(count <= n/2)
        return -1;
    return majority;
}
