//Link: https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

/*
You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.*/
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
 
// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    
    // Your logic here
    int ans=a^b;
    int c=0;
    while(ans>0)
    {
        ans &=(ans-1);
        c++;
    }
     return c;   
    
}

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends