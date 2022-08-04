void reverse(arr) {
  var low = 0;
  var high = arr.length - 1;

  while (low < high) {
    var temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;

    low++;
    high--;
  }
}

void main() {
  var arr = [1, 2, 3, 4, 5];
  print('Before Reverse: ${arr}');
  reverse(arr);
  print('After Reverse: ${arr}');
}
