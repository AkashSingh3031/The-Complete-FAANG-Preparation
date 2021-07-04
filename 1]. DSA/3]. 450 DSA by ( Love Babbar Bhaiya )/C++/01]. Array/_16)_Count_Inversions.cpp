#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeSort(long long arr[], long long temp[], int left, int right)
    {
        long long int mid, inv_count = 0;
        if (left < right)
        {
            mid = (left + right) / 2;

            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);

            inv_count += merge(arr, temp, left, mid + 1, right);
        }

        return inv_count;
    }

    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
    {
        long long int i, j, k;
        long long int inv_count = 0;
        i = left;
        j = mid;
        k = left;

        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];

                inv_count += (mid - i);
            }
        }

        while (i <= mid - 1)
        {
            temp[k++] = arr[i++];
        }

        while (j <= right)
        {
            temp[k++] = arr[j++];
        }

        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return inv_count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends