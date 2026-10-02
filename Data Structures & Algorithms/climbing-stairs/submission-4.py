class Solution:
    def climbStairs(self, n: int) -> int:
        ways = [1, 1] # start at the 0th step (only one way to get here), only one way to get to the first step (going up one from the second step)
        # the second step has two ways to reach (going up from the 0th step or the 1st step)
        # we can sum the number of ways to get to step 0 and to get to step 1, to get the number of ways to reach step 2
        # this property is inductive

        # O(n) time, O(1) space
        two_below = 0
        one_below = 1
        for _ in range(1, n):
            curr = one_below + two_below
            two_below = one_below
            one_below = curr
        
        return one_below + two_below