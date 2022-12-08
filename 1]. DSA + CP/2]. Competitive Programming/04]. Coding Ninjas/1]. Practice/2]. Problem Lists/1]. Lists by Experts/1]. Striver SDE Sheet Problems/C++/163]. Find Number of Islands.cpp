void floodfill(int** grid,int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return;
    if(grid[x][y]!=1)
        return;
    grid[x][y]=0;
    floodfill(grid,x,y+1,n,m); // East
    floodfill(grid,x,y-1,n,m); // West
    floodfill(grid,x-1,y,n,m); // North
    floodfill(grid,x+1,y,n,m); // South
    floodfill(grid,x-1,y-1,n,m); // NorthWest
    floodfill(grid,x+1,y-1,n,m); // SouthWest
    floodfill(grid,x-1,y+1,n,m); // NorthEast
    floodfill(grid,x+1,y+1,n,m); // SouthEast
}
int getTotalIslands(int** grid, int n, int m)
{
    // Write your code here.
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                count++;
                floodfill(grid,i,j,n,m);
            }
        }
    return count;
}