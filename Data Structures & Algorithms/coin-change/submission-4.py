class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        OPT(i) is the fewest number of coins to make exactly i cents
        let OPT(i) = {
            0 if i <= 0
            1 if i in coins
            1 + min(OPT(amount - coins[j])) for j in range 0...len(coins)
        }
        """
        table = [-2] * (amount + 1)
        table[0] = 0
        def opt(i):
            if table[i] != -2:
                return table[i]
            table[i] = -1
            for coin in coins:
                if i - coin >= 0:
                    num_coins = opt(i - coin)
                    if num_coins != -1:
                        if table[i] == -1:
                            table[i] = num_coins + 1
                        else:
                            table[i] = min(table[i], num_coins + 1)
            return table[i]
        return opt(amount)
