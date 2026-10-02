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

        O(n) time, O(n) space,
        Lets optimize for space
        """

        n = len(nums)
        curr_house_value = nums[n - 1]
        next_house_value = 0

        for idx in range(n - 2, -1, -1):
            prev_house_value = max(nums[idx] + next_house_value, curr_house_value)
            next_house_value = curr_house_value
            curr_house_value = prev_house_value
        
        return curr_house_value