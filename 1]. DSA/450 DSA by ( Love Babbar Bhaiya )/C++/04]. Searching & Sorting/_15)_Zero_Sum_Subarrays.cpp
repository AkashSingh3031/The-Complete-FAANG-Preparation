//Link : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

/*
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].*/
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

  
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        if(n==0) return 0;
        
        unordered_map <int ,int > m;
        int i=0,count=0,curr_sum=0;
        
        while(i<n)
        {
            curr_sum+= arr[i];
            if(curr_sum==0) count+=1;
            
            if(m.find(curr_sum)!=m.end()) count+= m[curr_sum];
            
            m[curr_sum]+=1;
            i++;
            
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends