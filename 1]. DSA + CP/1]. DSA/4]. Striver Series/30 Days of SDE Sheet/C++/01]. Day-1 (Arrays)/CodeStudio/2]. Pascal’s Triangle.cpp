#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    // Write your code here.
    vector<vector<long long int>> mat(n);
    
    for(int i=0; i<n; i++) {
        mat[i].resize(i+1);
        mat[i][0] = 1, mat[i][i] = 1;
        
        for(int j=1; j<i; j++)
            mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
    }
    return mat;
}
