//Link: https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

/*
Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

Example 1:

Input:
N = 2
Output:
2
Explanation:
2 is represented as "10" in Binary.
As we see there's only one set bit
and it's in Position 2 and thus the
Output 2.*/
#include <bits/stdc++.h>
using namespace std;
 

class Solution {
  public:
  
  int isPowerOfTwo(unsigned N) 
    { 
        return N && (!(N & (N - 1))); 
    } 
    int findPosition(int N) {
        // code here
        if (!isPowerOfTwo(N)) 
            return -1; 
  
        unsigned i = 1, pos = 1; 
      
        
        while (!(i & N)) { 
            
            i = i << 1; 
      
            // increment position 
            ++pos; 
        } 
      
        return pos; 
        
        }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends