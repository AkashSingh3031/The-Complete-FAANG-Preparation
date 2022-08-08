List<int> preSum(List<int> arr) {
  var perfixSum = List.filled(arr.length, 0);
  perfixSum[0] = arr[0];

  for (int i = 1; i < arr.length; i++) {
    perfixSum[i] = perfixSum[i - 1] + arr[i];
  }
  return perfixSum;
}

int getSum(List<int> arr, int l, int r) {
  var perfixSum = preSum(arr);
  if (l != 0) {
    return perfixSum[r] - perfixSum[l - 1];
  }
  return perfixSum[r];
}

void main() {
  var arr = [2, 8, 3, 9, 6, 5, 4];
  print('Sum of subarray index from 1 to 3 = ${getSum(arr, 1, 3)}');
  print('Sum of subarray index from 0 to 2 = ${getSum(arr, 0, 2)}');
}
