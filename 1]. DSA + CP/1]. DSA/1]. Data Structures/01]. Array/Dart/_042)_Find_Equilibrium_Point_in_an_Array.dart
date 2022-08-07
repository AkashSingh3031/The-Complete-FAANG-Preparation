bool checkEquilibrium(List<int> arr) {
  for (int i = 0; i < arr.length; i++) {
    int lSum = 0, rSum = 0;
    for (int j = 0; j < i; j++) lSum += arr[j];

    for (int j = i + 1; j < arr.length; j++) rSum += arr[j];

    if (lSum == rSum) return true;
  }
  return false;
}

void main() {
  var arr = [3, 4, 8, -9, 20, 6];
  print('Equilibrium = ${checkEquilibrium(arr)}');
}
