#include<bits/stdc++.h>
using namespace std;

class Solution
{   
public:

void setZeroes(vector<vector<int>>& matrix) 
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

int main() 
{
    int t;
    cin>>t;
    
    while(t--) 
    {
        int m, n;
        cin>>m>>n;
        vector<vector<int>> matrix(m, vector<int> (n, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin>>matrix[i][j];
        cout<<"\n";
        Solution ob;
        ob.setZeroes(matrix);
        for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                  cout<<matrix[i][j]<<" ";
                  
                cout<<endl;  
            }      
    }
    return 0;
} 
