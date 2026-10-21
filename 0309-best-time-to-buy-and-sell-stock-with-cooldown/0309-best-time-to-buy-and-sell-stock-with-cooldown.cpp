class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int rest = 0;

        for (int p : prices) {
            int oldHold = hold;
            int oldSold = sold;
            int oldRest = rest;

            hold = max(oldHold, oldRest - p);
            sold = oldHold + p;
            rest = max(oldRest, oldSold);
        }

        return max(sold, rest);
    }
};