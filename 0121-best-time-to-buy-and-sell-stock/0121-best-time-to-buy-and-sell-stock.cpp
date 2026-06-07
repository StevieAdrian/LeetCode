class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = prices[0];
        int maxProfit = 0;

        for (int i = 1; i <= prices.size() - 1; i++){
            if (buy >= prices[i]) {
                buy = prices[i];
            } else {
                profit = prices[i] - buy;
                maxProfit = max(maxProfit, profit);
            }

            // debug(profit);
        }

        return maxProfit;
    }
};