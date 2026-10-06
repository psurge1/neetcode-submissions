class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        """
        merging triplets involves taking the element wise maximum of each triplet
        A triplet is unusable if it has a single element at index i (0..2) such that triplet[i] > target[i]
        Thus, target is achievable if we can find a set of triplets where
        - for every i (0..2), target[i] is in at least one of the triplets in the set
        - triplet[i] <= target[i], for i (0..2), for all triplets in the set
        """

        satisfied_idx = [False] * 3

        for triplet in triplets:
            is_usable = True
            for idx in range(3):
                is_usable &= (triplet[idx] <= target[idx])
            if is_usable:
                for idx in range(3):
                    if triplet[idx] == target[idx]:
                        satisfied_idx[idx] = True

        result = True
        for res in satisfied_idx:
            result &= res
        return result