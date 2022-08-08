void printNbonacciNumbers(int n, int m) {
  var series = List.generate(m, (i) => 0);
  series[n - 1] = 1;
  series[n] = 1;
  for (int i = n + 1; i < m; i++) {
    series[i] = 2 * series[i - 1] - series[i - n - 1];
  }
  print('N-bonacci Numbers = $series.');
}

void main() {
  int n = 5;
  int m = 15;
  printNbonacciNumbers(n, m);
}
