//Link : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10*/
#include <bits/stdc++.h> 
using namespace std; 

  

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector <int > vec;
        int top=0 , down = r-1 , left =0, right=c-1;
        int dir=0;
        while(top<=down && left<=right)
        {
            if(dir==0) {for(int i=left;i<=right;i++) {
                vec.push_back(matrix[top][i]);}
                top+=1;
                
            }
            else if(dir==1) {for(int i=top;i<=down;i++) {
                vec.push_back(matrix[i][right]);}
                right-=1;
                
            }
            else if(dir==2) {for(int i=right;i>=left;i--) {
                vec.push_back(matrix[down][i]);}
                down-=1;
                
            }
            else if(dir==3) {for(int i=down;i>=top;i--) {
                vec.push_back(matrix[i][left]);}
                left+=1;
                
            }
            dir=(dir+1)%4;
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends