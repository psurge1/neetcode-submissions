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

        O(n) time, O(1) space
        """

        n = len(cost)
        cost_two_below = cost[0]
        cost_one_below = cost[1]
        for idx in range(2, n):
            curr_cost = min(cost_two_below, cost_one_below) + cost[idx]
            cost_two_below = cost_one_below
            cost_one_below = curr_cost
        
        return min(cost_two_below, cost_one_below)