var maxProfit = function(prices) {
    let minPrice = Number.MAX_VALUE;
    let maxProfit = 0;
    for(let i = 0; i < prices.length; i++) {
        if(prices[i] < minPrice) {
          minPrice = prices[i];
        }
        else if (prices[i] - minPrice > maxProfit) {
          maxProfit = prices[i] - minPrice;  
        }
      }
      return maxProfit;  
};

console.log(maxProfit([7,1,5,3,6,4]));