//Link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector< vector <int >  > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        set< vector <int > > s;
        int l,r,n=arr.size();
        sort(arr.begin(),arr.end());
        
        for (int i = 0; i < n - 3; i++)
        {
            if(i>0 and arr[i]==arr[i-1]) continue;
            for (int j = i+1; j < n - 2; j++)
            {
                if(j> i+1 and arr[j]==arr[j-1]) continue;
                // Initialize two variables as
                // indexes of the first and last
                // elements in the remaining elements
                l = j + 1;
                r = n-1;
     
                // To find the remaining two
                // elements, move the index
                // variables (l & r) toward each other.
                while (l < r)
                {
                    if( arr[i] + arr[j] + arr[l] + arr[r] == k)
                    {
                        vector <int > v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[l]);
                        v.push_back(arr[r]);
                        s.insert(v);
                        l++;  
                    }
                    else if (arr[i] + arr[j] + arr[l] + arr[r] < k)
                        l++;
                    else // A[i] + A[j] + A[l] + A[r] > X
                        r--;
                } // end of while
            } // end of inner for loop
        } // end of outer for loop
        vector < vector <int > > res;
        for(auto it: s) res.push_back(it);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends