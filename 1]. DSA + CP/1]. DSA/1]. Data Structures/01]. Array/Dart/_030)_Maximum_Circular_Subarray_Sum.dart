import 'dart:math';

int normalMaxSum(List<int> arr) {
  int res = arr[0];
  int maxEnding = arr[0];

  for (int i = 1; i < arr.length; i++) {
    maxEnding = max(maxEnding + arr[i], arr[i]);
    res = max(res, maxEnding);
  }
  return res;
}

int maxCircularSubArraySum(List<int> arr) {
  int maxNormal = normalMaxSum(arr);
  if (maxNormal < 0) return 0;

  int arrSum = 0;
  for (int i = 0; i < arr.length; i++) {
    arrSum += arr[i];
    arr[i] = -arr[i];
  }

  int maxCircular = arrSum + normalMaxSum(arr);
  return max(maxNormal, maxCircular);
}

void main() {
  var arr = [5, -2, 3, 4];
  print('Maximum circular sub-array sum is ${maxCircularSubArraySum(arr)}.');
}
