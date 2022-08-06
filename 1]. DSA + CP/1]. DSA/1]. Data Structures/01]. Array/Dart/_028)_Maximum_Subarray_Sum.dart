import 'dart:math';

int maxSubArraySum(List<int> arr) {
  int res = arr[0];
  int maxEnding = arr[0];

  for (int i = 1; i < arr.length; i++) {
    maxEnding = max(maxEnding + arr[i], arr[i]);
    res = max(res, maxEnding);
  }
  return res;
}

void main() {
  var arr = [2, 3, -8, 7, -1, 2, 3];
  print('Maximum sub-array sum is ${maxSubArraySum(arr)}.');
}
