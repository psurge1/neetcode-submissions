class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        
        neighborhood_one = nums[:n - 1]
        neighborhood_two = nums[1:]

        next_house_value = 0
        curr_house_value = neighborhood_one[n - 2]
        for idx in range(n - 3, -1, -1):
            prev_house_value = max(neighborhood_one[idx] + next_house_value, curr_house_value)
            next_house_value = curr_house_value
            curr_house_value = prev_house_value
        
        opt_one = curr_house_value

        next_house_value = 0
        curr_house_value = neighborhood_two[n - 2]
        for idx in range(n - 3, -1, -1):
            prev_house_value = max(neighborhood_two[idx] + next_house_value, curr_house_value)
            next_house_value = curr_house_value
            curr_house_value = prev_house_value
        return max(opt_one, curr_house_value)