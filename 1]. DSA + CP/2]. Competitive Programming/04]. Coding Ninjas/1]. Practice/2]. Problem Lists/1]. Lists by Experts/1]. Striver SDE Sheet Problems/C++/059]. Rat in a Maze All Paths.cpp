bool dfs(vector<vector<int>> &maze,int i,int j,vector<vector<int>> &ans,int n,vector<vector<int>> &res){
   if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 || ans[i][j]==1)
       return 0;
   if(i==n-1 && j==n-1 && maze[i][j]==1){
       vector<int> path;
       ans[i][j]=1;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               path.push_back(ans[i][j]);
           }
       }
       res.push_back(path);
   }
   
   ans[i][j]=1;
   dfs(maze,i+1,j,ans,n,res);
   dfs(maze,i-1,j,ans,n,res);
   dfs(maze,i,j+1,ans,n,res);
   dfs(maze,i,j-1,ans,n,res);
   ans[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans(n,vector<int>(n,0));
    vector<vector<int>> res;

    dfs(maze,0,0,ans,n,res);
    return res;
}