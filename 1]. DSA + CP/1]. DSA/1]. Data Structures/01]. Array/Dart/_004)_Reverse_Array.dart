reverse(arr) {
  var start = 0;
  var end = arr.length - 1;

  while (start < end) {
    var temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void main() {
  var arr = [1, 2, 3, 4, 5];
  print('Before Reverse: ${arr}');
  reverse(arr);
  print('After Reverse: ${arr}');
}
