class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """
        can perform "level-order-traversal" esque jump operations
        start at index 0, maintain a highest reachable and lowest reachable index for each level
        iterate through each number in the range (low, high), computing the next range of reachable elements
        repeat until high >= len(nums) - 1 (in which case we return true) OR the range reaches a deadend
        """

        low = 0
        high = 0
        while high < len(nums) - 1:
            new_low = high + 1
            new_high = 0
            for idx in range(low, high + 1):
                new_high = max(new_high, idx + nums[idx])
            if new_high < new_low:
                return False
            high = new_high
            low = new_low

        return True