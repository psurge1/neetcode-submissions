class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        the subarray sum grows with every positive number
        it shrinks with every negative number
        
        we can use a growing/shrinking window approach
        if the sum of the window is ever negative, we can reset the window 
        """

        right = 0
        max_sum = None
        running_sum = 0
        while right < len(nums):
            running_sum += nums[right]
            if max_sum is None or running_sum > max_sum:
                max_sum = running_sum
            running_sum = max(0, running_sum)
            right += 1
        return max_sum