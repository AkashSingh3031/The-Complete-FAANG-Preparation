void insert(arr, positon, element) {
  if (positon < 0 || positon > arr.length) {
    throw new Exception("Invalid position");
  }
  for (int i = positon; i < arr.length; i++) {
    var temp = arr[i];
    arr[i] = element;
    element = temp;
  }
  arr.add(element);
}

void main() {
  var arr = [1, 2, 3, 4, 5];
  print('Before Insertion: ${arr}');
  insert(arr, 2, 6);
  print('After Insertion: ${arr}');
}
