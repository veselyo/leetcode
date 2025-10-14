class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int profit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - currMin);
            currMin = min(currMin, prices[i]);
        }
        if (profit < 0) {
            return 0;
        } else {
            return profit;
        }
    }
};
