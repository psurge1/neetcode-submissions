struct value {
    bool isSet;
    int value;
};

class Solution {
private:
    int calculateProfit(int idx, int owned, const vector<int>& prices, vector<vector<value>>& table) {
        if (idx >= prices.size()) {
            return 0;
        }
        if (table[owned][idx].isSet) {
            return table[owned][idx].value;
        }

        //skip
        int profit = calculateProfit(idx + 1, owned, prices, table);
        
        if (!owned) {
            //buy
            profit = max(profit, calculateProfit(idx + 1, true, prices, table) - prices[idx]);
        }
        else {
            //sell
            profit = max(profit, prices[idx] + calculateProfit(idx + 2, false, prices, table));
        }
        table[owned][idx].value = profit;
        table[owned][idx].isSet = true;
        return table[owned][idx].value;
    }
public:
    int maxProfit(vector<int>& prices) {
        /*
        Either buy or sell a neetcoin
        Can only buy if we havent sold the previous day
        Can only sell if we own one (one day after)
        */
        vector<vector<value>> table(2, vector<value>(prices.size(), {false, 0}));

        return calculateProfit(0, 0, prices, table);
    }
};
