/*
    Time Complexity : O( N * M )
    Space Complexity : O( 1 )
    
    where 'N * M' is the size of matrix 'MAT'. 
*/

vector < vector < int > > mapMist(int n, int m, vector < vector < int > > mat) {

  // Iterating over the matrix 'MAT' only once.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      // Inverting values by subtracting current value from '1'.
      mat[i][j] = 1 - mat[i][j];
    }
  }

  // Returning 'MAT'.
  return mat;
}