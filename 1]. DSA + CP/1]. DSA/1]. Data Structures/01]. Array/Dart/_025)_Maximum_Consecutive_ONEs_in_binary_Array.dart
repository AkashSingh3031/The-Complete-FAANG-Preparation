import 'dart:math';

int maxConsecutiveOnes(arr) {
  var res = 0;

  for (var i = 0; i < arr.length; i++) {
    var count = 0;
    for (int j = i; j < arr.length; j++) {
      if (arr[j] == 1) {
        count++;
      } else {
        break;
      }
    }
    res = max(res, count);
  }
  return res;
}

void main() {
  var arr = [0, 1, 1, 0, 1, 1, 1];
  print('Max consecutive ones in binary array is ${maxConsecutiveOnes(arr)}.');
}
