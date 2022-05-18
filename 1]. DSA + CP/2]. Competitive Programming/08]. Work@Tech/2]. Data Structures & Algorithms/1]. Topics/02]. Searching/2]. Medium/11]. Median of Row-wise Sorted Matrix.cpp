/*
Exampl:
    1 2 3
    3 3 4
    1 1 2
    Median: 2
*/

int binarySearch(vector<vector<int>> &matrix, int r, int low,  int high, int requiredIndx) {
   	if(high > low) {
       	int mid =(high + low) / 2, currentIndx = 0;
           
       	for(int i = 0; i < r; i++) {
           	currentIndx += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
       	}
       	if(currentIndx < requiredIndx) {
           	return binarySearch(matrix, r, mid+1, high, requiredIndx);
       	} 
		else {
           	return binarySearch(matrix, r, low, mid, requiredIndx);
       	}
   	}
   	return low;
}

int calculateMedianOfMatrix(vector<vector<int>> &matrix) {
   	int rowSize = matrix.size(), columnSize = matrix[0].size();
   	int low = INT_MAX, high = INT_MIN;
   	for(int i = 0; i < rowSize; i++) {
       	low = min(matrix[i][0], low);
       	high = max(matrix[i][columnSize-1], high);
   	}
   	int requiredIndx =(rowSize * columnSize + 1) / 2;
   	return binarySearch(matrix, rowSize, low, high,  requiredIndx);
}