class Solution:
    def climbStairs(self, n: int) -> int:
        ways = [1, 1] # start at the 0th step (only one way to get here), only one way to get to the first step (going up one from the second step)
        # the second step has two ways to reach (going up from the 0th step or the 1st step)
        # we can sum the number of ways to get to step 0 and to get to step 1, to get the number of ways to reach step 2
        # this property is inductive

        # O(n) time, O(n) space
        for step in range(2, n + 1):
            ways.append(ways[step - 1] + ways[step - 2])
        
        return ways[n]