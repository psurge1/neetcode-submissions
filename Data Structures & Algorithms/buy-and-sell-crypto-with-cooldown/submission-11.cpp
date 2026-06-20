class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        Doesn't work as intended (need to track state of cooldown)
        Previously calculated max profits don't track whether a sale or purchase occured at said price, so we have no information about cooldown
        Include a third dimension for cooldown so we have more knowledge (1 or 0 for true or false, or days left on cooldown)
        */
        int numPrices = prices.size();
        // table[i][j] gives the max profit when considering the j + 1th price with ownership i 
        int maxSharesPurchaseable = 1; // max number of shares of stock that you can own at any given time
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
