Link : https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

/*
Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets with the sum smaller than the given sum value X.

 

Example 1:

Input: N = 6, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). */
#include <bits/stdc++.h>
using namespace std;

 
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    long long count=0;
	    for(long long i=0;i<n-2;i++)
	    {
	        long long l=i+1;
	        long long r=n-1;
	        while(l<r)
	        {
	            if(arr[i]+arr[l]+arr[r] < sum) {count+=(r-l);
	            l++;
	            }
	            else r--;
	        }
	    }
	    return count;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends