import 'dart:math';

int maxSubArraySum(arr) {
  int res = arr[0];

  for (int i = 0; i < arr.length; i++) {
    int curr = 0;
    for (int j = i; j < arr.length; j++) {
      curr += arr[j] as int;
      res = max(res, curr);
    }
  }
  return res;
}

void main() {
  var arr = [2, 3, -8, 7, -1, 2, 3];
  print('Maximum sub-array sum is ${maxSubArraySum(arr)}.');
}
