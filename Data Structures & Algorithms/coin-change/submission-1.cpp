class Solution {
private:
    int opt(int amount, vector<int>& coins, vector<int>& table) {
        if (amount < 0) {
            return -1;
        }
        if (table[amount] != INT_MAX) {
            return table[amount];
        }

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int numCoins = opt(amount - coin, coins, table);
            if (numCoins != -1 && 1 + numCoins < minCoins) {
                minCoins = 1 + numCoins;
            }
        }
        if (minCoins == INT_MAX) {
            minCoins = -1;
        }
        table[amount] = minCoins;
        return table[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // let opt(j) denote the optimal number of coins to reach amount j
        int numCoins = coins.size();
        vector<int> table(amount + 1, INT_MAX);
        table[0] = 0;
        int result = opt(amount, coins, table);
        for (int t : table) {
            cout << t << " ";
        }
        cout << endl;
        return result;
    }
};
