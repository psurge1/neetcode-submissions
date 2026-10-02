class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """
        let OPT(i) be the minimum cost to reach step i
        want to find OPT(n + 1), where n = len(cost)

        let OPT(i) = {
            cost[0] if idx = 0
            cost[1] if idx = 1
            max(cost[idx - 1], cost[idx - 2]) + cost[idx] otherwise
        }
        """

        n = len(cost)
        dp = [0] * (n + 1)
        dp[0] = cost[0]
        dp[1] = cost[1]
        for idx in range(2, n + 1):
            dp[idx] = min(dp[idx - 1], dp[idx - 2])
            if idx < n:
                dp[idx] += cost[idx]
        
        return dp[n]