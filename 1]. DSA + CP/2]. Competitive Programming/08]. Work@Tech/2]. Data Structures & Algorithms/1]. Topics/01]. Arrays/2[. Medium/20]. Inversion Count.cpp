/*
Example
    Array: 8, 4, 1, 2

    Inversion Count: 5. ==> (8, 4), (8, 1), (8, 2), (4, 1), (4, 2)
*/

int merge (vector<int> &arr, int low, int mid, int high) {
   	int subArr1Size = mid - low + 1, subArr2Size = high - mid;
   	vector<int> subArr1, subArr2;
   	
	for (int i = 0; i < subArr1Size; i++) {
       	subArr1.push_back (arr[low + i]);
   	}
	
   	for (int i = 0; i < subArr2Size; i++) {
       	subArr2.push_back (arr[mid + 1 + i]);
   	}
	
   	int i = 0, j = 0, k = low, inversions = 0;
   	while (i < subArr1Size && j < subArr2Size) {
       	if( subArr1[i] <=  subArr2[j]) {
           	arr[k] = subArr1[i];
           	i++;
       	} 
	   	else {
           	arr[k] = subArr2[j];
           	j++;
           	inversions += mid + 1 - (low + i);
       	}
       	k++;
   	}
	
   	while (i < subArr1Size) {
       	arr[k++] = subArr1[i++];
   	}
	
   	while (j < subArr2Size) {
       	arr[k++] = subArr2[j++];
   	}
   	return inversions;
}

int mergesort (vector<int> &arr, int low, int high) {
   	int inversions = 0;
   	
	if (high > low) {
       	int mid = (high + low) / 2;
       	inversions += mergesort (arr, low, mid);
       	inversions += mergesort (arr, mid + 1, high);
       	inversions += merge (arr, low, mid, high);
   	}
   	return inversions;
}

int getInversionCount(vector<int> array) {
   	return mergesort(array, 0, array.size() - 1);
}