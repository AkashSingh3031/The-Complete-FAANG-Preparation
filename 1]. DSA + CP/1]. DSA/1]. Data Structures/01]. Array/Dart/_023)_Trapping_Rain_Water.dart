import 'dart:math';

int getWater(arr) {
  int res = 0;

  for (int i = 1; i < arr.length - 1; i++) {
    int lMax = arr[i];
    for (int j = 0; j < i; j++) lMax = max(lMax, arr[j]);
    int rMax = arr[i];
    for (int j = i + 1; j < arr.length; j++) rMax = max(rMax, arr[j]);

    res += min(lMax, rMax) - arr[i] as int;
  }

  return res;
}

void main(List<String> args) {
  var arr = [3, 0, 1, 2, 5];
  print('Maximum fill boxes = ${getWater(arr)}');
}
