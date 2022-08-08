bool checkEquilibrium(List<int> arr) {
  int sum = 0;

  for (int i = 0; i < arr.length; i++) sum += arr[i];

  int lSum = 0;

  for (int i = 0; i < arr.length; i++) {
    if (lSum == sum - arr[i]) return true;
    lSum += arr[i];
    sum -= arr[i];
  }

  return false;
}

void main() {
  var arr = [3, 4, 8, -9, 20, 6];
  print('Equilibrium = ${checkEquilibrium(arr)}');
}
