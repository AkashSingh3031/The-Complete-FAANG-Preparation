/*
	Time Complexity : O(N*M)
	Space Complexity : O(N+M)

	Where 'N' is the number of rows in 'MAT' and 'M' is the number of 
	columns in 'MAT'.
*/
#include <vector>
using namespace std;

int MaxMatrixZeroes(int n, int m, vector<vector<int>> mat) {

	// Vectors to store the number of '1's in each column and in each row.
	vector<int> Ones_Row(n,0);
	vector<int> Ones_Column(m,0);

	// Integer variable 'total' to store the total number of '1's in the matrix
	int total = 0;

	// Integer variable 'answer' to store the final answer.
	int answer = -1;

	// Iterate over the cells of 'MAT'.
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {

			/* If a cell [i,j] is '1', increment 'total', the corresponding vectors
			'Ones_Row' and 'Ones_Column'. */

			if(mat[i][j] == 1) {
				total++;
				Ones_Row[i]++;
				Ones_Column[j]++;
			}
		}
	}

	/* Iterate over the cells of matrix and treat each cell as an intersection
	of a unique [row,column] combination .*/
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {

			/* Integer variable 'current' to find the number of '1's that will be obtained if
			the flipping operation is performed on the 'ith' row followed by the flipping operation
			on the 'jth' column. */
			int current = total - Ones_Row[i] - Ones_Column[j] + (m - Ones_Row[i]) + (n - Ones_Column[j]);
			if(mat[i][j] == 1) {
				current += 2;
			}
			else {
				current -= 2;
			}

			// Update 'answer' as the max of 'current' and 'answer'.
			answer = max(answer, current);
		}
	}
	// Return 'answer' as the final output.
	return answer;
}