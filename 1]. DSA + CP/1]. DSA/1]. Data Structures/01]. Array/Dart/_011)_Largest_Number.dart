import 'dart:math';

int getLargest(arr) {
  var res = 0;
  for (var i = 1; i < arr.length; i++) {
    if (arr[i] > arr[res]) res = i;
  }
  return res;
}

void main() {
  var arr = [10, 100, 20, 70, 40, 50, 60, 30, 80, 90];
  var index = getLargest(arr);
  print('Largest element in ${arr} is ${arr[index]}.');

  var largestNum = arr.reduce((value, element) => max(value, element));
  print('Largest element in ${arr} is $largestNum.');
}
