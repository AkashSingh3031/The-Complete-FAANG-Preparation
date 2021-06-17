//Link : https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

/*
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.*/

#include<bits/stdc++.h>
using namespace std;
 
// Function to count set bits in the given number x
// n: input to count the number of set bits
int largestpowerof2inrange(int n)
{
    int x=0;
    while((1<<x) <=n)
    {
        x++;
    }
    return x-1;
}
int countSetBits(int n)
{
    // Your logic 
    if(n==0) return 0;
    int x=largestpowerof2inrange(n);
    int first= x*(1<<(x-1));
    int second= n-(1<<x)+1;
    int third=n-(1<<x);
    int ans=first+second+countSetBits(third);
    return ans;
}
 
// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends