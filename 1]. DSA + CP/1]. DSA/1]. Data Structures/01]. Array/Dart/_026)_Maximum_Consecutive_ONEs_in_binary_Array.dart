import 'dart:math';

int maxConsecutiveOnes(arr) {
  var res = 0;
  var count = 0;
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] == 0) {
      count = 0;
    } else {
      count++;
      res = max(res, count);
    }
  }
  return max(res, count);
}

void main() {
  var arr = [0, 1, 1, 0, 1, 1, 1];
  print('Max consecutive ones in binary array is ${maxConsecutiveOnes(arr)}.');
}
