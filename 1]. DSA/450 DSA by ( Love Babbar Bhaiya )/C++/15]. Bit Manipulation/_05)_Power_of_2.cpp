//Link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
/*
Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.
 

Example 1:

Input: N = 1
Output: true
Explanation:
1 is equal to 2 raised to 0 (20 = 1).*/
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
 
// Function to check power of two
bool isPowerofTwo(long long n){
    
    // Your code here 
    if(n==0)
        return 0;
        
    else if(n>0)
    {
        if((n & n-1)==0)
            return 1;
    }
    return 0;
}
 
// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

         if(isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}
  // } Driver Code Ends