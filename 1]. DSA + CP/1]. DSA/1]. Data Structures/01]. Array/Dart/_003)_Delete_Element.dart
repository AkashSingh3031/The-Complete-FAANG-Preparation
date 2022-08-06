List<int> delete(arr, element) {
  if (arr.indexOf(element) == -1) {
    throw new Exception("Element does not exist in array");
  }
  var newArr = <int>[];
  for (int i = 0; i < arr.length; i++) {
    if (arr[i] != element) {
      newArr.add(arr[i]);
    }
  }
  return newArr;
}

void main() {
  var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  print('Before Deletion: ${arr}');
  var delArr = delete(arr, 6);
  print('After Deletion: ${delArr}');
}
