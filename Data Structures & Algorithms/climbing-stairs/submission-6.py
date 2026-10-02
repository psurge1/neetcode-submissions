class Solution:
    def climbStairs(self, n: int) -> int:
        prev_step_ways = 0
        curr_step_ways = 1
        for step in range(n):
            next_step_ways = curr_step_ways + prev_step_ways
            prev_step_ways = curr_step_ways
            curr_step_ways = next_step_ways
        return curr_step_ways