function maxProfit(price, start, end) {
    if (end <= start) return 0;
    let profit = 0;
    for (let i = start; i < end; i++) {
        for (let j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                let cur_profit =
                    price[j] -
                    price[i] +
                    maxProfit(price, start, i - 1) +
                    maxProfit(price, j + 1, end);
                profit = Math.max(profit, cur_profit);
            }
        }
    }
    return profit;
}

let price = [1, 5, 3, 8, 12];
let start = 0;
let end = 5;
console.log(`Maximum Profit in Stock Market = ${maxProfit(price, start, end)}`);
