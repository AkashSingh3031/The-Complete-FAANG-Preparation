#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int buy = prices[0], res = 0;
    for(int i=1; i<prices.size(); i++) {
        res = max(res, prices[i]-buy);
        buy = min(buy, prices[i]);
    }
    return res;
}
