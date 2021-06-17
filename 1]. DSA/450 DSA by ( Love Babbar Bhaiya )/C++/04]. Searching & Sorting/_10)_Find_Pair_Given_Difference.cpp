//Link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

/*
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.*/
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    // Initialize positions of two elements 
    int i = 0; 
    int j = 1; 
  
    // Search for a pair 
    while (i < size && j < size) 
    { 
        if (i != j && abs(arr[j] - arr[i]) == n) 
        { 
            return true; 
        } 
        else if (arr[j]-arr[i] < n ) 
            j++; 
        else
            i++; 
    } 
    return false; 
    
}