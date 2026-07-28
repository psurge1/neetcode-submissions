class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        solution = []
        numsLen = len(nums)
        nums.sort()
        idx = 0
        while idx < numsLen:
            seenNums = set()
            jdx = idx + 1
            while jdx < numsLen:
                target = -(nums[idx] + nums[jdx])
                if target in seenNums:
                    solution.append([nums[idx], nums[jdx], target])
                    jdx += 1
                    while jdx < numsLen and nums[jdx] == nums[jdx - 1]:
                        jdx += 1
                else:
                    seenNums.add(nums[jdx])
                    jdx += 1
                
                # the purpose of this set is to track the "middle" element of a triplet
                # we want to check the sum of nums[idx] and nums[jdx] against numbers already visited
                # nums[idx] <= numbers in set < nums[jdx]
                
                
            idx += 1
            while idx < numsLen and nums[idx] == nums[idx - 1]:
                idx += 1
        
        return solution