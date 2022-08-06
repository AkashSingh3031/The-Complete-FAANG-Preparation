int maxDiff(arr) {
  var n = arr.length;
  var res = arr[1] - arr[0];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] - arr[i] > res) {
        res = arr[j] - arr[i];
      }
    }
  }
  return res;
}

void main() {
  var arr = [2, 3, 10, 6, 4, 8, 1];
  var diff = maxDiff(arr);
  print('Leaders in the array are: $diff');
}
