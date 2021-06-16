// Link : https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

/*
Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}*/

#include <bits/stdc++.h>
using namespace std;


  
class Solution{
    public:
    
    static bool compare(int a, int b)
    {
        // __builtin_popcount is a stl to count set bits.
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr,arr+n,compare);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends