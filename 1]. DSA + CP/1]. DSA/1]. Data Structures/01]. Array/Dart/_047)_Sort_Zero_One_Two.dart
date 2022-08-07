/*
Input: [0, 2, 2, 1, 0, 1, 1, 0, 2]
Output: [0, 0, 0, 1, 1, 1, 2, 2, 2]
*/

void sortOneTwo(List<int> arr) {
  int left = 0, mid = 0, right = arr.length - 1;

  while (mid <= right) {
    if (arr[mid] == 0) {
      int temp = arr[left];
      arr[left] = arr[mid];
      arr[mid] = temp;
      left++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else if (arr[mid] == 2) {
      int temp = arr[mid];
      arr[mid] = arr[right];
      arr[right] = temp;
      right--;
    }
  }
}

void main() {
  var arr = [0, 2, 2, 1, 0, 1, 1, 0, 2];
  print('Array before sorting: ${arr}');
  sortOneTwo(arr);
  print('Array after sorting: ${arr}');
}
