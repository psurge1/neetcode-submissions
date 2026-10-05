class Solution:
    def jump(self, nums: List[int]) -> int:
        low = 0
        high = 0
        jumps = 0

        while high < len(nums) - 1:
            jumps += 1
            new_low = high + 1
            new_high = 0
            for idx in range(low, high + 1):
                new_high = max(new_high, idx + nums[idx])
            high = new_high
            low = new_low

        return jumps