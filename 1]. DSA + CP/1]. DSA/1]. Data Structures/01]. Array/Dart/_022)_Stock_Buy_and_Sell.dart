int maxProfit(price) {
  int profit = 0;

  for (int i = 1; i < price.length; i++) {
    if (price[i] > price[i - 1]) {
      profit += (price[i] - price[i - 1]) as int;
    }
  }

  return profit;
}

void main() {
  var price = [1, 5, 3, 8, 12];
  print('Maximum Profit in Stock Market = ${maxProfit(price)}');
}
