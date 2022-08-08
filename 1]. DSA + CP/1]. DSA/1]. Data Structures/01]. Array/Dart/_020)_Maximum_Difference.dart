import 'dart:math';

int maxDiff(arr) {
  int n = arr.length;
  int res = arr[1] - arr[0];
  int minVal = arr[0];

  for (int i = 1; i < n; i++) {
    res = max(res, arr[i] - minVal);
    minVal = min(minVal, arr[i]);
  }
  return res;
}

void main() {
  var arr = [2, 3, 10, 6, 4, 8, 1];
  var diff = maxDiff(arr);
  print('Leaders in the array are: $diff');
}
