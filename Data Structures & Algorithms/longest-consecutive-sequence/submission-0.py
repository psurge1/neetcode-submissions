class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        longest = 0
        for num in nums:
            if num - 1 not in nums:
                sequenceSize = 1
                while num + 1 in nums:
                    sequenceSize += 1
                    num += 1
                longest = max(longest, sequenceSize)
        return longest
        
        