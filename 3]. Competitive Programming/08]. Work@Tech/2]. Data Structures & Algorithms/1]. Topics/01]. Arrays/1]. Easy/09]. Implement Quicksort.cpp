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

int makePartition (vector<int> &arr, int low, int high) {
   int pivot = arr[high];
   int currentIndx = low - 1;
	
   for (int i = low; i < high; i++) {
       if (arr[i] < pivot) {
           currentIndx++;
           int temp = arr[i];
           arr[i] = arr[currentIndx];
           arr[currentIndx] = temp;
       }
   }
	
   int temp = arr[high];
   arr[high] = arr[currentIndx + 1];
   arr[currentIndx + 1] = temp;
   return currentIndx + 1;
}

void quicksort (vector<int> &arr, int low, int high) {
   if (low < high) {
       int pivot = makePartition (arr, low, high);
       quicksort (arr, low, pivot - 1);
       quicksort (arr, pivot + 1, high);
   }
}

void quickSort(vector<int> &arr) {
   int n = arr.size();
   quicksort (arr, 0, n-1);
}