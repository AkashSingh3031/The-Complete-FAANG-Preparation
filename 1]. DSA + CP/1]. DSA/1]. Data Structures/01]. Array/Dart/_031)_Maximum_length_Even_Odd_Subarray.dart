import 'dart:math';

int maxEvenOdd(List<int> arr) {
  int res = 1;

  for (int i = 0; i < arr.length; i++) {
    int curr = 1;
    for (int j = i + 1; j < arr.length; j++) {
      if ((arr[j] % 2 == 0 && arr[j - 1] % 2 == 0) ||
          (arr[j] % 2 != 0 && arr[j - 1] % 2 != 0)) {
        curr++;
      } else {
        break;
      }
    }
    res = max(res, curr);
  }

  return res;
}

void main() {
  var arr = [10, 12, 14, 7, 8];
  print('Maximum length of Even Odd Subarray: ${maxEvenOdd(arr)}');
}
