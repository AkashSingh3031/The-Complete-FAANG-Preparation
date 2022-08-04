void leftRotateOne(arr, int n) {
  var temp = arr[0];
  for (int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
}

void leftRotate(arr, int d, int n) {
  for (int i = 0; i < d; i++) {
    leftRotateOne(arr, n);
  }
}

void main(List<String> args) {
  var arr = [1, 2, 3, 4, 5];
  print('Before Left Rotate: ${arr}');
  leftRotate(arr, 2, arr.length);
  print('After Left Rotate: ${arr}');
}
