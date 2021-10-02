#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& A, int n) 
    { 
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                swap(A[i][j], A[j][i]);
            }
        }
        
        for(int j = 0; j < n; j++)
          {
              int s = 0;
              int e = n - 1;
              while(s < e)
              {
                  swap(A[s][j], A[e][j]);
                  s++;
                  e--;
              }
          }
    } 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
