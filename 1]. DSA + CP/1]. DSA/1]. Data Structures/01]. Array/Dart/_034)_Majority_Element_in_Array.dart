int majorityElementIndex(List<int> arr) {
  int res = 0;
  int count = 1;

  for (int i = 1; i < arr.length; i++) {
    if (arr[res] == arr[i]) {
      count++;
    } else {
      count--;
    }

    if (count == 0) {
      res = i;
      count = 1;
    }
  }

  count = 0;
  for (int i = 0; i < arr.length; i++) {
    if (arr[res] == arr[i]) count++;
  }

  if (count <= arr.length ~/ 2) return -1;

  return res;
}

void main() {
  var arr = [2, 3, 4, 5, 5, 5, 5];
  print('Index of Majority Element in Array: ${majorityElementIndex(arr)}');
}
