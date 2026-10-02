class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        OPT(i) gives the max amount of stealable money starting at house i
        let OPT(i) = {
            nums[n - 1] if i = n - 1
            # either rob this house, or skip it and rob the next one
            max(nums[i] + OPT(i + 2), OPT(i + 1)) otherwise
        }
        OPT(0) yields the result
        """

        n = len(nums)
        profits = [0] * n
        profits[n - 1] = nums[n - 1]

        for idx in range(n - 2, -1, -1):
            next_house_value = 0
            if idx < n - 2:
                next_house_value = profits[idx + 2]
            profits[idx] = max(nums[idx] + next_house_value, profits[idx + 1])
        
        return profits[0]