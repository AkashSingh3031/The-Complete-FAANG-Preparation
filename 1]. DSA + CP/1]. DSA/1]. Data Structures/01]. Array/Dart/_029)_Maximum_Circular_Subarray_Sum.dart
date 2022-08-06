import 'dart:math';

int maxCircularSubArraySum(List<int> arr) {
  int res = arr[0];

  for (int i = 0; i < arr.length; i++) {
    int currMax = arr[i];
    int currSum = arr[i];

    for (int j = 1; j < arr.length; j++) {
      int index = (i + j) % arr.length;
      currSum += arr[index];
      currMax = max(currMax, currSum);
    }
    res = max(res, currMax);
  }
  return res;
}

void main() {
  var arr = [5, -2, 3, 4];
  print('Maximum circular sub-array sum is ${maxCircularSubArraySum(arr)}.');
}
