void solve(int i, int j, vector<vector<int>> &image, int n, int m, int oldColor, int newColor){
    if(i<0 || j<0 || i>n-1 || j>m-1 || image[i][j] != oldColor) return;
    
    image[i][j] = newColor;
    solve(i+1, j, image, n, m, oldColor, newColor);
    solve(i-1, j, image, n, m, oldColor, newColor);
    solve(i, j+1, image, n, m, oldColor, newColor);
    solve(i, j-1, image, n, m, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    
    int oldColor = image[x][y];
    if(newColor == oldColor) return image;
    
    
    solve(x, y, image, n, m, oldColor, newColor);
    return image;
}