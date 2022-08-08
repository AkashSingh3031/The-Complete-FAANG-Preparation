import 'dart:math';

int maxEvenOdd(List<int> arr) {
  int res = 1;
  int curr = 1;

  for (int i = 1; i < arr.length; i++) {
    if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) ||
        (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)) {
      curr++;
      res = max(res, curr);
    } else {
      curr = 1;
    }
  }

  return res;
}

void main() {
  var arr = [10, 12, 14, 7, 8];
  print('Maximum length of Even Odd Subarray: ${maxEvenOdd(arr)}');
}
