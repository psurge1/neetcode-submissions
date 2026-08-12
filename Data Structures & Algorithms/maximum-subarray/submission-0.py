class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        keep track of a window of numbers with a positive sum
        if the sum ever drops below 0, reset the window
        """

        maxSum = nums[0]
        currSum = nums[0]
        for idx in range(1, len(nums)):
            if currSum < 0:
                currSum = nums[idx]
            else:
                currSum += nums[idx]
            maxSum = max(maxSum, currSum)
        return maxSum