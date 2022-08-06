void leftRotateOne(arr) {
  var temp = arr[0];
  for (int i = 1; i < arr.length; i++) {
    arr[i - 1] = arr[i];
  }
  arr[arr.length - 1] = temp;
}

void main() {
  var arr = [1, 2, 3, 4, 5];
  print('Before Left Rotate: ${arr}');
  leftRotateOne(arr);
  print('After Left Rotate: ${arr}');
}
