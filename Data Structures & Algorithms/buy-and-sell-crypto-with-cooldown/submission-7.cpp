class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        Either buy or sell a neetcoin
        Can only buy if we havent sold the previous day
        Can only sell if we own one (one day after)
        */
        int numPrices = prices.size();
        // table[i][j] gives the max profit when considering the j + 1th price with ownership i 
        int maxSharesPurchaseable = 1;
        vector<vector<int>> table(maxSharesPurchaseable + 1, vector<int>(numPrices + 2));
        for (int share = 0; share <= maxSharesPurchaseable; ++share) {
            table[share][numPrices] = 0;
            table[share][numPrices + 1] = 0;
        }
        for (int idx = numPrices - 1; idx >= 0; --idx) {
            for (int stocksOwned = 0; stocksOwned <= maxSharesPurchaseable; ++stocksOwned) {
                int profit = table[stocksOwned][idx + 1];
                if (stocksOwned > 0) {
                    // can sell stock
                    profit = max(profit, table[stocksOwned - 1][idx + 2] + prices[idx]);
                }
                if (stocksOwned < maxSharesPurchaseable) {
                    profit = max(profit, table[stocksOwned + 1][idx + 1] - prices[idx]);
                }
                table[stocksOwned][idx] = profit;
            }
        }

        return table[0][0];
    }
};
