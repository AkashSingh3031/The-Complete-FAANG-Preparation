void leftRotate(arr, int d, int n) {
  var temp = List.empty(growable: true)..length = d;

  for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
  }
  for (int i = d; i < n; i++) {
    arr[i - d] = arr[i];
  }
  for (int i = 0; i < d; i++) {
    arr[n - d + i] = temp[i];
  }
}

void main() {
  var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  print('Before Left Rotate: ${arr}');
  leftRotate(arr, 3, arr.length);
  print('After Left Rotate: ${arr}');
}
