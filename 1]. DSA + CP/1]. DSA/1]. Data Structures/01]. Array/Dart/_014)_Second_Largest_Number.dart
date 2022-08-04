int getSecondLargest(arr) {
  var res = -1, largest = 0;
  for (var i = 1; i < arr.length; i++) {
    if (arr[i] > arr[largest]) {
      res = largest;
      largest = i;
    } else if (arr[i] != arr[largest]) {
      if (res == -1 || arr[i] > arr[res]) res = i;
    }
  }
  return res;
}

void main() {
  var arr = [10, 100, 20, 70, 40, 50, 60, 30, 80, 90];
  var index = getSecondLargest(arr);
  print('Second largest element in ${arr} is ${arr[index]}.');
}
