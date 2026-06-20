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
        vector<vector<int>> table(2, vector<int>(numPrices + 2));
        table[0][numPrices] = 0;
        table[1][numPrices] = 0;
        table[0][numPrices + 1] = 0;
        table[1][numPrices + 1] = 0;
        for (int idx = numPrices - 1; idx >= 0; --idx) {
            int keepStock = table[1][idx + 1];
            int dontBuyStock = table[0][idx + 1];

            int buyStock = table[1][idx + 1] - prices[idx];
            int sellStock = table[0][idx + 2] + prices[idx];

            table[0][idx] = max(dontBuyStock, buyStock);
            table[1][idx] = max(keepStock, sellStock);
        }

        return table[0][0];
    }
};
