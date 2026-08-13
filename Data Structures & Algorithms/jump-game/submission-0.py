class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lower = 0
        upper = 0
        n = len(nums)
        while upper < n - 1 and upper >= lower:
            maxJump = 0
            for idx in range(lower, upper + 1):
                maxJump = max(maxJump, idx + nums[idx])
            lower = upper + 1
            upper = min(n - 1, maxJump)
        return upper == n - 1
        