int findMaxOccuringElement(List<int> L, List<int> R) {
  Map<int, int> map = {};
  for (int i = 0; i < L.length; i++) {
    if (map.containsKey(L[i]))
      map[L[i]]! + 1;
    else
      map[L[i]] = 1;
  }
  int max = 0;
  int maxElement = 0;
  for (int i = 0; i < R.length; i++) {
    if (map.containsKey(R[i])) {
      if (map[R[i]]! > max) {
        max = map[R[i]]!;
        maxElement = R[i];
      }
    }
  }
  return maxElement;
}

void main() {
  var L = [1, 2, 3], R = [3, 5, 7];
  print(
      'Maximum Occuring Element in both Array = ${findMaxOccuringElement(L, R)}');
}
