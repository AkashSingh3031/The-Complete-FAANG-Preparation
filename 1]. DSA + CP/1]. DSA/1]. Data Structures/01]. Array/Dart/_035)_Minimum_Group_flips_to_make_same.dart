import 'dart:io';

void minGroupFlipSame(List<int> arr) {
  for (int i = 1; i < arr.length; i++) {
    if (arr[i] != arr[i - 1]) {
      if (arr[i] != arr[0])
        stdout.write('From $i to ');
      else
        stdout.writeln(i - 1);
    }
  }

  if (arr[arr.length - 1] != arr[0]) stdout.writeln(arr.length - 1);
}

void main() {
  var arr = [1, 1, 0, 0, 0, 0, 0, 1, 1, 0];
  minGroupFlipSame(arr);
}
