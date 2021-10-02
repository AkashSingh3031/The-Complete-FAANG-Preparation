#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 0 then all the cells in its ith row and jth column will become 0.
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row = false, col = false;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0) 
                {
                    if(i == 0) 
                        row = true;
                    if(j == 0) 
                        col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }
        }
        if(col)
        {
            for(int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }     
        if(row)
        {
            for(int j = 0; j < matrix[0].size(); j++) 
                matrix[0][j] = 0;
        }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
