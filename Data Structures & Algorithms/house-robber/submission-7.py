class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        table = [0] * n
        table[n - 1] = nums[n - 1]
        if n > 1:
            table[n - 2] = max(nums[n - 1], nums[n - 2])
        for i in range(n - 3, -1, -1):
            table[i] = max(table[i + 1], nums[i] + table[i + 2])
        return table[0]