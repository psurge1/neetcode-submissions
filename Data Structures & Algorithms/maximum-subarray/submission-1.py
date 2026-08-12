class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        Inputs:
        - an array of integers (can be negative, zero, or positive)

        Goal:
        - find a continuous subarray with the largest possible sum

        Approaches:
        - Brute Force:
            - Consider every possible subarray, tracking the sum
            - Keep track of the maximum sum we encounter
            - Nested forloop -> O(n^2) time, O(1) space
        - Sliding Window:
            - Because continuous subarrays can be represented as "windows"
            - We can grow a window, and every number in the window contributes to the sum
            - If the window sum is ever negative, just restart the window
            - O(n) time, O(1) space
        """

        maxSum = nums[0]
        windowSum = nums[0]
        for idx in range(1, len(nums)):
            if windowSum < 0:
                windowSum = nums[idx]
            else:
                windowSum += nums[idx]
            maxSum = max(maxSum, windowSum)
        return maxSum