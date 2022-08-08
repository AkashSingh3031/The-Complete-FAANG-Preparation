import 'dart:math';

int getWater(arr) {
  int res = 0;
  var lMax = List.empty(growable: true)..length = arr.length;
  var rMax = List.empty(growable: true)..length = arr.length;

  lMax[0] = arr[0];
  for (int i = 1; i < arr.length; i++) {
    lMax[i] = max(arr[i] as int, lMax[i - 1] as int);
  }

  rMax[arr.length - 1] = arr[arr.length - 1];
  for (int j = arr.length - 2; j >= 0; j--) {
    rMax[j] = max(arr[j] as int, rMax[j + 1] as int);
  }

  for (int k = 1; k < arr.length - 1; k++) {
    res += min(lMax[k] as int, rMax[k] as int) - arr[k] as int;
  }

  return res;
}

void main(List<String> args) {
  var arr = [3, 0, 1, 2, 5];
  print('Maximum fill boxes = ${getWater(arr)}');
}
