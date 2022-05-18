//Link : https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
/*
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome*/
#include <bits/stdc++.h>
using namespace std;
 
class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    // Your code goes here
	    
	    int start=0,end=s.length()-1; 
	    int flag=0;
	     
	    while(start<end)
	    {
	         if(s[start]!=s[end]) flag=1;
	         start++;
	         end--;
	    }
	     
	    if(flag==1) return 0;
	    else return 1;
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends