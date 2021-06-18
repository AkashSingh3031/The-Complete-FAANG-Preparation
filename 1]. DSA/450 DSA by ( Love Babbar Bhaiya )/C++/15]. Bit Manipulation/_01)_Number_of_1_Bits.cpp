//Link : https://practice.geeksforgeeks.org/problems/set-bits0143/1
/*
Given a positive integer N, print count of set bits in it. 

Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110' 
So the count of the set bit is 2.*/
#include<bits/stdc++.h> 
using namespace std; 

  

class Solution
{
public:
    int setBits(int N)
    {
       int count =0;   
        while (N) { 
            N &=(N-1);
            count ++;
              
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
        int N;
        cin >> N;
        
        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends