class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return max(nums)
        
        prev = nums[n - 1]
        curr = max(prev, nums[n - 2])
        for i in range(n - 3, -1, -1):
            next = max(curr, nums[i] + prev)
            prev = curr
            curr = next
        return curr