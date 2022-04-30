/*
Examples-1:
    Matrix:
        1 2 3
        4 5 6
        7 8 9
    After rotation:
        7 4 1
        8 5 2
        9 6 3

Example-2:
    Matrix:
        1 2
        3 4
        5 6
    After rotation:
        5 3 1
        6 4 2
*/

vector<vector<int> > rotateMatrix(vector<vector<int> > &matrix){
    int numRows = matrix.size();
   	int numCols = matrix[0].size();
   	vector<vector<int>> rotatedMatrix(numCols, vector<int> (numRows));
   
	for (int i = 0; i < numRows; i++) {
       	for (int j = 0; j < numCols; j++) {
           	rotatedMatrix[j][i] = matrix[i][j];
       	}
   	}
	
   	for(auto &x: rotatedMatrix) {
       	reverse(x.begin(), x.end());
   	}
   	return rotatedMatrix;
}