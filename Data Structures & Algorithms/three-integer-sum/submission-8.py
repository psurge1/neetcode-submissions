class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        numsDict = {num: idx for idx, num in enumerate(nums)}

        solution = set()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                target = -(nums[i] + nums[j])
                if target in numsDict and numsDict[target] != i and numsDict[target] != j:
                    solution.add(tuple(sorted((nums[i], nums[j], target))))
        result = [list(item) for item in solution]
        return result