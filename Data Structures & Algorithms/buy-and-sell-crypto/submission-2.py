class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        min_price = prices[0]
        for day in range(1, len(prices)):
            max_profit = max(max_profit, prices[day] - min_price)
            min_price = min(min_price, prices[day])


        return max_profit