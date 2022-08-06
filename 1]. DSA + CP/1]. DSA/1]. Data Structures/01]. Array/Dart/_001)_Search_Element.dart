int searchElement(var arr, var element) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] == element) {
      return i;
    }
  }
  return -1;
}

main() {
  var arr = [1, 20, 33, 47, 5, 67, 71, 85, 9, 10];
  var result = searchElement(arr, 71);
  if (result == -1) {
    print('Element not found!');
  } else {
    print('Element found at index $result.');
  }
}
