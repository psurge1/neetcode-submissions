class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        numsLen = len(nums)
        target = None
        solutions = []
        for lowerBound in range(len(nums)):
            if target is not None and nums[lowerBound] == -target:
                continue
             
            target = -nums[lowerBound]
            left = lowerBound + 1
            right = numsLen - 1
            while left < right:
                innerSum = nums[left] + nums[right]
                if innerSum == target:
                    solutions.append([nums[lowerBound], nums[left], nums[right]])
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                elif innerSum < target:
                    left += 1
                else:
                    right -= 1
        
        return solutions