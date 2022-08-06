List flatten(arr) {
  var temp = [];
  process(arr, temp);
  return temp;
}

void process(arr, output) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] is List) {
      process(arr[i], output);
    } else {
      output.add(arr[i]);
    }
  }
}

void main() {
  var arr = [
    [2, 5, 8, 1],
    10,
    [
      [
        80,
        [45, 86, 98],
        30
      ]
    ],
    4,
    0,
    7,
    [
      12,
      [16, 25]
    ]
  ];
  print('Before flatten array: ${arr}');
  var temp = flatten(arr);
  print('After flatten array: ${temp}');
}
