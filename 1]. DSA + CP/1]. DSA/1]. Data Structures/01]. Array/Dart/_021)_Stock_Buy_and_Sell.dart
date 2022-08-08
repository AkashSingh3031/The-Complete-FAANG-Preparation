import 'dart:math';

int maxProfit(price, start, end) {
  if (end <= start) return 0;
  int profit = 0;

  for (int i = start; i < end; i++) {
    for (int j = i + 1; j < end; j++) {
      if (price[j] > price[i]) {
        int currProfit = (price[j] - price[i]) +
            maxProfit(price, start, i - 1) +
            maxProfit(price, j + 1, end);
        profit = max(profit, currProfit);
      }
    }
  }
  return profit;
}

void main() {
  var price = [1, 5, 3, 8, 12];
  int start = 0, end = 5;
  print('Maximum Profit in Stock Market = ${maxProfit(price, start, end)}');
}
