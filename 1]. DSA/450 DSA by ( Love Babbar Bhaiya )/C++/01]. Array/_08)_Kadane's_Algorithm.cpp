//Link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

/* Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

 

Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int i,maxCur=arr[0];
    int totalsum=arr[0];
    for(i=1;i<n;i++)
    {
        maxCur=max(arr[i],arr[i]+maxCur);
        if(maxCur>totalsum)
        {
            totalsum=maxCur;
        }
    }
    return totalsum;
    
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends