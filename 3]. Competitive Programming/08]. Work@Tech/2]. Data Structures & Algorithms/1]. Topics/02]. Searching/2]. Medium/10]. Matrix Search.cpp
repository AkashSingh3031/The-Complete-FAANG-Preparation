/*
Example-1:
    Matrix:
        1 2 3
        4 5 6
        7 8 9
    Key: 6

    Answer: true


Example-2:
    Matrix:
        1 2 3
        4 5 6
        7 8 9
        10 11 12
    Key: 15

    Answer: false
*/

bool searchMatrix(vector<vector<int>> &matrix, int key) {
   	int rowSize = matrix.size(), columnSize = matrix[0].size();
   	int low = 0, high = rowSize - 1, mid, row = - 1;
   	while (low <= high) {
       	mid = (high + low) / 2;
       	if (matrix [mid][0] <= key && matrix [mid][columnSize - 1] >= key) {
           	row = mid;
           	break;
       	} 
		else if (matrix [mid][0] > key ) {
           	high = mid - 1;
       	} 
		else {
           	low = mid + 1;
       	}
   	}
   
   	if (row == - 1) {
       	return false;
   	} 
	else {
       	low = 0;
       	high = columnSize-1;
       	while (low <= high) {
           	mid = (high + low) / 2;
           	if (matrix [row][mid] == key) {
               	return true;
           	} 
			else if (matrix [row][mid] < key) {
               	low = mid + 1;
           	} 
			else {
               	high = mid - 1;
           	}
       	}
       	return false;
   	}
}