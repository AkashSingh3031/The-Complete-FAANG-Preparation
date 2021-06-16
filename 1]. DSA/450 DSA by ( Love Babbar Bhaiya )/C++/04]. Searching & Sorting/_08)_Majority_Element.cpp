//Link:https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int c=0;
        int elem=0;
        for(int i=0;i<size;i++)
        {
            if(c==0)
            {
                elem=a[i];
            }
            if(a[i]==elem)
            {
                c+=1;
            }
            else c-=1;
        }
        int x=elem;
        
        int count = 0;
        for (int i = 0; i < size; i++)
            if (a[i] == x)
                count++;
     
        if (count > size / 2) 
        { 
            int val= x; 
            return val;
            
        } 
        return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends