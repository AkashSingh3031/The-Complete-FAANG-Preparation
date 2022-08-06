void reverse(arr, low, high) {
  while (low < high) {
    var temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;

    low++;
    high--;
  }
}

void leftRotate(arr, d, n) {
  reverse(arr, 0, d - 1);
  reverse(arr, d, n - 1);
  reverse(arr, 0, n - 1);
}

void main() {
  var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  print('Before Left Rotate: ${arr}');
  leftRotate(arr, 4, arr.length);
  print('After Left Rotate: ${arr}');
}
