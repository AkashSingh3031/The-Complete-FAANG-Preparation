List remDups(arr) {
  var i = 0;
  while (i < arr.length - 1) {
    if (arr[i] == arr[i + 1]) {
      arr.removeAt(i);
    } else {
      i++;
    }
  }
  return arr;
}

void main() {
  var arr = [0, 20, 20, 30, 30, 30, 30, 50, 70];
  print('Before Duplicate Removal: ${arr}');
  var newArr = remDups(arr);
  print('After Duplicate Removal: ${newArr}');
}
