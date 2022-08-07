int majorityElement(List<int> arr) {
  for (int i = 0; i < arr.length; i++) {
    int count = 0;
    for (int j = 0; j < arr.length; j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }
    if (count > arr.length ~/ 2) {
      return arr[i];
    }
  }
  return -1;
}

void main() {
  var arr = [2, 3, 4, 5, 5, 5, 5];
  print('Majority Element in Array: ${majorityElement(arr)}');
}
