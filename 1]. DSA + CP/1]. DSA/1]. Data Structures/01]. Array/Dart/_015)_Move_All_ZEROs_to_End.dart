void moveToEnd(arr) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] == 0) {
      for (var j = i + 1; j < arr.length; j++) {
        if (arr[j] != 0) {
          //swaping the values
          var temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
          break;
        }
      }
    }
  }
}

void main() {
  var arr = [1, 0, 0, 1, 0, 1, 0, 0, 0, 1];
  print('Before moving zeros: ${arr}');
  moveToEnd(arr);
  print('After moving zeros: ${arr}');
}
