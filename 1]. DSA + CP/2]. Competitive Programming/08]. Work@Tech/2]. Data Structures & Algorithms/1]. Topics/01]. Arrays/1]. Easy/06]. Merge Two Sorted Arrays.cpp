/*
Example:
    Input-1: [1, 2, 3, 4, 4]
    Input-2: [2, 4, 5, 5]

    Output:  [1, 2, 2, 3, 4, 4, 4, 5, 5]
*/

vector<int> mergeSortedArrays(vector<int> &A, vector<int> B) {
    // add your logic here
	vector<int> C(A.size() + B.size());
   	int i = 0, j = 0, k = 0;
   	while (i < A.size() && j < B.size()) {
       	if(A[i] < B[j]) {
           	C[k] = A[i];
           	k++;
           	i++;
       	}
       	else {
           	C[k] = B[j];
           	k++;
           	j++;
       	}
   	}
   	while (i < A.size()) {
       	C[k] = A[i];
       	k++;
       	i++;
   	}
   	while (j < B.size()) {
       	C[k] = B[j];
       	k++;
       	j++;
   	}
   	return C;
}