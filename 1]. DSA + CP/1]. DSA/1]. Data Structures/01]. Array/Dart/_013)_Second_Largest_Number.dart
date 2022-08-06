int getLargest(arr) {
  var res = 0;
  for (var i = 1; i < arr.length; i++) {
    if (arr[i] > arr[res]) res = i;
  }
  return res;
}

int getSecondLargest(arr) {
  var largest = getLargest(arr);
  var res = -1;
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] != arr[largest]) {
      if (res == -1)
        res = i;
      else if (arr[i] > arr[res]) res = i;
    }
  }
  return res;
}

void main() {
  var arr = [10, 100, 20, 70, 40, 50, 60, 30, 80, 90];
  var index = getSecondLargest(arr);
  print('Second largest element in ${arr} is ${arr[index]}.');
}
