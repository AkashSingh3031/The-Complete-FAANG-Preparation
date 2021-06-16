// Link : https://practice.geeksforgeeks.org/problems/count-squares3649/1

/*Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

 

Example 1:

Input :
N = 9
Output:
2
Explanation:
1 and 4 are the only Perfect Squares
less than 9. So, the Output is 2.*/

#include <bits/stdc++.h>
using namespace std;

  

class Solution {
  public:
    int countSquares(int N) {
        // code here
        int count =0;
        for(int i=1;i<sqrt(N);i++)
        {
            if(i*i < N) count++;
        }
        return count;
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
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends