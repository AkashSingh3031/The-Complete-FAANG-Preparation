/*
Sample Input:
    2              // Test Case Number
    5              // Number of elements
      4 2 5 3 1
    3              // Number of elements
      11 4 200
      
Expected Output:
    1 2 3 4 5
    4 11 200
*/

void merge (vector<int> &arr, int low, int mid, int high) {
   int subArr1Size = mid - low + 1, subArr2Size = high - mid;
   vector<int> subArr1, subArr2;
	
   for (int i = 0; i < subArr1Size; i++) {
       subArr1.push_back (arr[low + i]);
   }
	
   for (int i = 0; i < subArr2Size; i++) {
       subArr2.push_back (arr[mid + 1 + i]);
   }
	
   int i = 0, j = 0, k = low;
   while (i < subArr1Size && j < subArr2Size) {
       if( subArr1[i] <=  subArr2[j]) {
           arr[k] = subArr1[i];
           i++;
       } else {
           arr[k] = subArr2[j];
           j++;
       }
       k++;
   }
	
   while (i < subArr1Size) {
       arr[k++] = subArr1[i++];
   }
	
   while (j < subArr2Size) {
       arr[k++] = subArr2[j++];
   }
}

void mergesort (vector<int> &arr, int low, int high) {
   if (high > low) {
       int mid = (high + low) / 2;
       mergesort (arr, low, mid);
       mergesort (arr, mid + 1, high);
       merge (arr, low, mid, high);
   }
}

void mergeSort(vector<int> &arr) {
   int n = arr.size();
   mergesort (arr, 0, n - 1);
}