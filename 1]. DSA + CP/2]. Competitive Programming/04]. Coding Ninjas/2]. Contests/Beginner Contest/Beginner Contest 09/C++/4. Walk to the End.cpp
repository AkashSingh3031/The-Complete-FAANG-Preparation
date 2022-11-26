/*
    Time Complexity : O( N * M )
    Space Complexity : O( N * M )
    
    where 'N * M' is the size of maze.
*/

int endOfMaze(int n, int m, int k) {

  int inf = 1e9;

  // Initialising 'DP' of size ' (N + 1) * (M + 1) ' with value 'INF'.
  vector < vector < int > > dp(n + 1, vector < int > (m + 1, inf));

  // We will simulate our walk and save minimum.
  
  dp[1][1] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      
      // Storing minimum of both possible moves.
      if(i - 1 > 0){
         dp[i][j] = min(dp[i][j] , j * k + dp[i - 1][j]);
      }
      if(j - 1 > 0){
         dp[i][j] = min(dp[i][j] , i * k + dp[i][j - 1]);
      }
      
    }

  }

  // Returning 'ANS'.
  return dp[n][m];
}