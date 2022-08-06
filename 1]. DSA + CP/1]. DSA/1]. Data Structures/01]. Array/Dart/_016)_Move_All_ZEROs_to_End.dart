void moveToEnd(arr) {
  var count = 0;
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] != 0) {
      //swaping the values
      var temp = arr[i];
      arr[i] = arr[count];
      arr[count] = temp;
      count++;
    }
  }
}

void main() {
  var arr = [5, 0, 0, 4, 0, 7, 0, 0, 0, 3];
  print('Before moving zeros: ${arr}');
  moveToEnd(arr);
  print('After moving zeros: ${arr}');
}
