List<int> findArrayIntersection(List<int> arr1, List<int> arr2) {
  List<int> result = [];

  int i = 0, j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] == arr2[j]) {
      result.add(arr1[i]);
      i++;
      j++;
    } else if (arr1[i] < arr2[j]) {
      i++;
    } else {
      j++;
    }
  }

  return result;
}

void main() {
  var arr1 = [4, 2, 3, 1, 10, 12, 5, 20, 16];
  var arr2 = [12, 5, 20, 2, 0, 1];

  var result = findArrayIntersection(arr1, arr2);
  print(result);
}
