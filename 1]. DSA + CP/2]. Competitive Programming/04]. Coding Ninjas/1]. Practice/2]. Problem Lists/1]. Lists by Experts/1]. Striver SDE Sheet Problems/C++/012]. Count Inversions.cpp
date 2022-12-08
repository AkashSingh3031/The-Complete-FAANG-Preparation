#include <bits/stdc++.h> 

long long merge(long long *arr, long long *temp, long long left, long long mid, long long right){
    int inv_count = 0;
    int i = left, j = mid, k = left;
    while((i <= mid-1) and (j <= right)){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_count += (mid-i);
        }
    }
    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    for(long long i=left; i<=right; i++)
        arr[i] = temp[i];
    return inv_count;
}

long long merge_sort(long long *arr, long long *temp, long long left, long long right){
    long long mid, inv_count = 0;
    if(left < right) {
        mid = (left+right)/2;
        
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid+1, right);
        
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n];
    return merge_sort(arr, temp, 0, n-1);
}
