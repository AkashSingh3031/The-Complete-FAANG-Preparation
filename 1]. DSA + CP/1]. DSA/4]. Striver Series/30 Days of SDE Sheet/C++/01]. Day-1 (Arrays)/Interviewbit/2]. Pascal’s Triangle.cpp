vector<vector<int>> Solution::solve(int A) {
    vector<vector<int>> mat(A);
    for(int i=0; i<A; i++) {
        mat[i].resize(i+1);
        mat[i][0]= 1, mat[i][i] = 1;
            
        for(int j=1; j<i; j++)
            mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
    }
    return mat;
}
