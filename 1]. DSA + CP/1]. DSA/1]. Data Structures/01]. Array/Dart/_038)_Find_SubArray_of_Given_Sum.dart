void subArraySum(List<int> arr, int reqSum) {
  for (int i = 0; i < arr.length; i++) {
    int sum = 0;
    for (int j = i; j < arr.length; j++) {
      sum += arr[j];
      if (sum == reqSum) {
        print('Sum found between indexes $i to $j.');
        return;
      }
    }
  }
  print('Sum not found.');
}

void main() {
  var arr = [1, 4, 20, 3, 10, 5];
  int sum = 23;
  subArraySum(arr, sum);
}
