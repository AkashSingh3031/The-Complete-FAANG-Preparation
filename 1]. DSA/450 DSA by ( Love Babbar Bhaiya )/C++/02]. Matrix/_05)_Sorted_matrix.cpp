//Link : https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
/*
Given an NxN matrix Mat. Sort all elements of the matrix.

Example 1:

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
Explanation:
Sorting the matrix gives this result.*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

  
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector< int > vec;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) 
            {
                vec.push_back(Mat[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Mat[i][j] = vec[cnt++];
            }
        }
        return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends