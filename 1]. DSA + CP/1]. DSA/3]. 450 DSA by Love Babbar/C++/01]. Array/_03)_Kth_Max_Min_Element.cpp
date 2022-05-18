/*
Example 1:
    Input:
        N = 6
        arr[] = 7 10 4 3 20 15
        K = 3
    Output : 7
    
  Explanation :
    3rd smallest element in the given 
    array is 7.

Example 2:
    Input:
        N = 5
        arr[] = 7 10 4 20 15
        K = 4
    Output : 15
    
  Explanation :
    4th smallest element in the given 
    array is 15.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    int kthSmallest(int arr[], int l, int r, int k){
        if(k>0 && k<=r-l+1)
        {
            int n = r-l+1;
            int i, median[(n+4)/5];
            for(i=0; i<n/5; i++)
                median[i] = findMedian(arr+l+i*5, 5);
            if(i*5 < n)
            {
                median[i] = findMedian(arr+l+i*5, n%5);
                i++;
            }
            
            int medOfMeds = (i==1) ? median[i-1] : kthSmallest(median, 0, i-1, i/2);
            
            int pos = partition(arr, l, r, medOfMeds);
            
            if(pos-l == k-1)
                return arr[pos];
            if(pos-l > k-1)
                return kthSmallest(arr, l, pos-1, k);
            
            return kthSmallest(arr, pos+1, r, k-pos+l-1);
        }
    }
    
    int findMedian(int arr[], int n)
    {
        sort(arr, arr+n);
        return arr[n/2];
    }
    
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    int partition(int arr[], int l, int r, int x)
    {
        int i;
        for(i=l; i<r; i++)
            if(arr[i] == x)
                break;
        swap(&arr[i], &arr[r]);
        
        i=l;
        for(int j=l; j<=r-1; j++)
        {
            if(arr[j] <= x)
            {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[r]);
        return i;
    }
};
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
