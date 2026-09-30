class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            int cost= prices[i]-buy;
            buy=min(buy,prices[i]);
            profit=max(cost,profit);
        }
        return profit;
    }
};