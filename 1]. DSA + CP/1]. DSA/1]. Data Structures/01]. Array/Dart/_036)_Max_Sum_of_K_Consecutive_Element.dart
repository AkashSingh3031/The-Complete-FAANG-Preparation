import 'dart:math';

int maxSumOfKElements(List<int> arr, int k) {
  int maxSum = 0;

  for (int i = 0; i + k - 1 < arr.length; i++) {
    int sum = 0;
    for (int j = 0; j < k; j++) {
      sum += arr[i + j];
    }
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}

void main() {
  var arr = [1, 8, 30, -5, 20, 7];
  int k = 3;
  print(
      'Maximum Sum of $k consecutive elements = ${maxSumOfKElements(arr, k)}');
}
