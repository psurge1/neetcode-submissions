class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        we only make one transaction (one buy and one sell)
        or no transactions at all
        
        Brute force: compare O(n^2) combinations of buy and sell prices
        Sliding window: left ptr points to cheapest price, right pointer points to highest price
        */

        int buy = 0;
        int sell = 1;
        int maxProfit = 0;

        while (sell < prices.size()) {
            if (prices[sell] <= prices[buy]) {
                buy = sell;
            }
            else {
                maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            }
            ++sell;
        }

        return maxProfit;
    }
};
