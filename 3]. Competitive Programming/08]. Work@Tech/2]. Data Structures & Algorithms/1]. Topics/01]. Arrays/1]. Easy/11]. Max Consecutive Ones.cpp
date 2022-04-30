/*
Examples
    A: [1, 1, 3, 2, 3, 1, 1, 1]
    Max consecutive 1s: 3
*/

int getMaxConsecutiveOnes(vector<int> &A) {
    // add your logic here
	int islandSize = 0, maxIslandSize = 0;
   	for(int i = 0; i < A.size(); i++) {
       	if(A[i] == 1) {
           	islandSize++;
		}
		else {
           	maxIslandSize = max(maxIslandSize, islandSize);
           	islandSize = 0;
       	}
   	}
   	if(islandSize != 0) {
       	maxIslandSize = max(maxIslandSize, islandSize);
   	}
   	return maxIslandSize;
}