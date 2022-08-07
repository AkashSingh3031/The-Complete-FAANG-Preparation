import 'dart:math';

int maxSumOfKElements(List<int> arr, int k) {
  int currMax = 0;
  for (int i = 0; i < k; i++) {
    currMax += arr[i];
  }
  int maxSum = currMax;

  for (int i = k; i < arr.length; i++) {
    currMax += (arr[i] - arr[i - k]);
    maxSum = max(maxSum, currMax);
  }
  return maxSum;
}

void main() {
  var arr = [1, 8, 30, -5, 20, 7];
  int k = 3;
  print(
      'Maximum Sum of $k consecutive elements = ${maxSumOfKElements(arr, k)}');
}
