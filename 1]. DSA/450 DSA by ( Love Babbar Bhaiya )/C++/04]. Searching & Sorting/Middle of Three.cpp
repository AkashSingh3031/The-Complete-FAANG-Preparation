//Link: https://practice.geeksforgeeks.org/problems/middle-of-three2926/1
/* 
Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).


Example 1:

Input:
A = 978, B = 518, C = 300
Output:
518
Explanation:
Since 518>300 and 518<978, so 
518 is the middle element.*/
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

  
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here 
        if( (A > B  && A < C) || (A > C  && A < B) ) return A;
        else if((B > A  && B < C) || (B > C  && B < A)) return B;
        else return C;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends