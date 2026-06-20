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
                // skip stock
                int profit = table[stocksOwned][idx + 1];
                for (int nextSharesOwned = 0; nextSharesOwned <= maxSharesPurchaseable; ++nextSharesOwned) {
                    int stockDiff = stocksOwned - nextSharesOwned;
                    if (stockDiff > 0) {
                        // sell stock
                        profit = max(profit, table[nextSharesOwned][idx + 2] + stockDiff * prices[idx]);
                    }
                    else if (stockDiff < 0) {
                        // buy stock
                        profit = max(profit, table[nextSharesOwned][idx + 1] + stockDiff * prices[idx]);
                    }
                }
                table[stocksOwned][idx] = profit;
            }
        }

        return table[0][0];
    }
};
