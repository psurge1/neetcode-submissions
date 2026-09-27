class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        inputs:
        - nums: an array of integers in the range [1, n]
        - all numbers in the array (but one) are unique

        output:
        - integer: the duplicate value in the array
        """

        slow_ptr = nums[0]
        fast_ptr = nums[nums[0]]
        while slow_ptr != fast_ptr:
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[nums[fast_ptr]]
        
        slow_ptr = 0
        while slow_ptr != fast_ptr:
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[fast_ptr]
        
        return slow_ptr