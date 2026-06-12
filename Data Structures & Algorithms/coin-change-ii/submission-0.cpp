class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // let opt(i, j) denote the number of unique combinations to make subamount j, given coins >= coin_i
        /*
            amount
          0 1 2 3 4
        0 1 1
        1 1 0
        2 1 0
        
        */
        sort(coins.begin(), coins.end());
        int numCoins = coins.size();

        vector<vector<int>> opt(numCoins, vector<int>(amount + 1, 1));
        for (int subAmount = 1; subAmount <= amount; ++subAmount) {
            for (int coinIdx = numCoins - 1; coinIdx >= 0; --coinIdx) {
                opt[coinIdx][subAmount] = 0;
                if (coins[coinIdx] <= subAmount) {
                    if (coinIdx < numCoins - 1) {
                        opt[coinIdx][subAmount] += opt[coinIdx + 1][subAmount];
                    }
                    opt[coinIdx][subAmount] += opt[coinIdx][subAmount - coins[coinIdx]];
                }
            }
        }

        return opt[0][amount];
    }
};
