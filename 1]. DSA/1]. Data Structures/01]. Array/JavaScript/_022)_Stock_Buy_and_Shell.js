function maxProfit(price) {
    let profit = 0;
    for (let i = 1; i < price.length; i++)
        if (price[i] > price[i - 1]) profit += price[i] - price[i - 1];
    return profit;
}

let price = [1, 5, 3, 8, 12];
console.log(`Maximum Profit in Stock Market = ${maxProfit(price)}`);
