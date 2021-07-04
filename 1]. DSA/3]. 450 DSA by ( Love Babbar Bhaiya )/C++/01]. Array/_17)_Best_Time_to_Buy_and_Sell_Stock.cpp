class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy=prices[0],ans=0;
        for(int i=1;i<prices.size();i++)
        {
            ans=max(ans,prices[i]-buy);
            buy=min(buy,prices[i]);
        }
        return ans;
    }
};