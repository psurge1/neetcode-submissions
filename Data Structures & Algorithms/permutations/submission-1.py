class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = [[]]
        for num in nums:
            new_permutations = []
            for p in permutations:
                k = len(p)
                for insert_idx in range(0, k + 1):
                    new_permutations.append(p[:insert_idx] + [num] + p[insert_idx:])

            permutations = new_permutations
        return permutations