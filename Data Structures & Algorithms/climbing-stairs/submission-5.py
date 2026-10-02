class Solution:
    def climbStairs(self, n: int) -> int:
        ways = [1, 1]
        for step in range(2, n + 1):
            ways.append(ways[step - 1] + ways[step - 2])
        return ways[n]