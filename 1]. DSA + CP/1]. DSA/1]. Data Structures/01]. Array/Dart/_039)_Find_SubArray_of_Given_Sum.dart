void subArraySum(List<int> arr, int reqSum) {
  int sum = arr[0];
  int start = 0;
  for (int end = 1; end < arr.length; end++) {
    while (sum > reqSum && start < end - 1) {
      sum -= arr[start];
      start++;
    }
    if (sum == reqSum) {
      print("Subarray found.");
      print("Start: $start End: ${end - 1}");
      return;
    }
    if (end < arr.length) sum += arr[end];
  }

  print("Subarray not found.");
}

void main() {
  var arr = [1, 4, 20, 3, 10, 5];
  int sum = 23;
  subArraySum(arr, sum);
}
