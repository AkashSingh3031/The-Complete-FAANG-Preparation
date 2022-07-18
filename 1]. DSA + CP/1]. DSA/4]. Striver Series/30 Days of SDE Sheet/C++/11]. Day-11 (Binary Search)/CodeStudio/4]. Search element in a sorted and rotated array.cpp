int pivot(int* arr, int n)
{
   int lo = 0, hi = n - 1, mid = lo + (hi - lo) / 2;
   while (lo < hi)
   {
       if (arr[mid] >= arr[0])
           lo = mid + 1;
       else
           hi = mid;
       mid = lo + (hi - lo) / 2;
   }
   return lo;
}

int binary_search(int arr[],int lo,int hi,int key)
{
    int mid=lo+(hi-lo)/2;
    while(lo<=hi)
    {  
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            lo=mid+1;
        else
            hi=mid-1;
        mid=lo+(hi-lo)/2;
    }
    return -1;
}

int search(int* arr, int n, int key) {
   // Write your code here.
   int s=0,e=n-1,ans=0;
   int pivot_res=pivot(arr,n);
   if(arr[pivot_res]<=key && key<=arr[e])
       ans= binary_search(arr,pivot_res,e,key);
   else
       ans=binary_search(arr,s,pivot_res-1,key);
   return ans;
}